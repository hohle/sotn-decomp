// SPDX-License-Identifier: AGPL-3.0-or-later
#include "bo0.h"

s16 func_us_801AD26C(s16 arg0, s16 arg1, s16 arg2) {
    s16 diff;

    arg1 &= 0xFFF;
    arg2 &= 0xFFF;
    diff = arg2 - arg1;
    if (diff > 0x800) {
        diff = diff - 0x1000;
    }
    if (diff < -0x800) {
        diff = diff + 0x1000;
    }
    if (diff < -arg0) {
        diff = -arg0;
    }
    if (diff > arg0) {
        diff = arg0;
    }
    arg2 = arg1 + diff;
    arg2 &= 0xFFF;
    return arg2;
}

bool func_us_801AD2F0(s16 x, s16 y) {
    Collider collider;
    g_api.CheckCollision(x, y, &collider, 0);
    if (collider.effects & EFFECT_SOLID) {
        return true;
    } else {
        return false;
    }
}

INCLUDE_RODATA("boss/bo0/nonmatchings/2D26C", D_us_801A9344);

INCLUDE_ASM("boss/bo0/nonmatchings/2D26C", func_us_801AD338);

INCLUDE_ASM("boss/bo0/nonmatchings/2D26C", func_us_801AE858);

INCLUDE_ASM("boss/bo0/nonmatchings/2D26C", func_us_801AF31C);

extern EInit D_us_801806E4;
extern s32 D_us_80180BA8;
extern u8 D_us_80180D68[];
extern u8 D_us_80180D74[];

// Skulls that come from the Portal
void func_us_801AF604(Entity* self) {
    Entity* entity;
    Entity* player;
    s16 angle;
    s16 offX, offY;

    if (D_us_80180BA8 != 0) {
        self->flags |= FLAG_DEAD;
    }

    if (self->flags & FLAG_DEAD) {
        PlaySfxPositional(0x655);
        entity = AllocEntity(&g_Entities[224], &g_Entities[256]);
        if (entity != NULL) {
            CreateEntityFromEntity(E_ID(LASER_EXPLOSION), self, entity);
            entity->params = 2;
        }
        DestroyEntity(self);
        return;
    }

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_801806E4);
        self->hitboxState = 0;
        self->drawFlags |= 8;
        self->hitboxOffY = -1;
        self->ext.ILLEGAL.s16[0x17] = ((Random() & 0x3F) * 0x10) + 0x200;
        if (self->params) {
            self->step = 2;
            self->zPriority -= 1;
            self->hitboxState = 0;
            self->blendMode |= 0x30;
            return;
        }
        entity = AllocEntity(&g_Entities[224], &g_Entities[256]);
        if (entity != NULL) {
            CreateEntityFromEntity(E_ID(UNK_2F), self, entity);
            entity->params = 1;
            entity->ext.olroxAfterImage.parent = self;
        }
        break;
    case 1:
        if (self->opacity < 0x80) {
            self->opacity += 4;
            self->hitboxState = 0;
        } else {
            self->hitboxState = 3;
        }
        AnimateEntity(D_us_80180D74, self);
        MoveEntity();
        if (self->velocityX > 0) {
            self->facingLeft = true;
        } else {
            self->facingLeft = false;
        }
        player = &PLAYER;
        offX = player->posX.i.hi - self->posX.i.hi;
        offY = player->posY.i.hi - self->posY.i.hi;
        offY -= 32;
        angle = ratan2(-offY, offX);
        angle = func_us_801AD26C(8,
                                 self->ext.ILLEGAL.s16[0x17],
                                 angle);
        self->velocityX = rcos(angle) * 16;
        self->velocityY = rsin(angle) * -16;
        self->ext.ILLEGAL.s16[0x17] = angle;
        break;
    case 2:
        AnimateEntity(D_us_80180D68, self);
        entity = self->ext.olroxAfterImage.parent;
        self->posX.i.hi = entity->posX.i.hi;
        self->posY.i.hi = entity->posY.i.hi;
        self->opacity = entity->opacity;
        if (!entity->entityId) {
            DestroyEntity(self);
        }
        break;
    }
}

extern u8 D_us_80180D7C[];
extern EInit g_EInitOlroxAfterImage;

void func_us_801AF8C0(Entity* self) {
    Entity* entity;

    entity = self->ext.olroxAfterImage.parent;
    if (entity->flags & FLAG_DEAD) {
        self->flags |= FLAG_DEAD;
        self->step = 3;
    }

    switch (self->step) {
    case 0:
        InitializeEntity(g_EInitOlroxAfterImage);
        self->animCurFrame = 0x54;
        self->drawFlags |= 3;
        self->scaleX = self->scaleY = 0;
        self->zPriority -= 1;
        self->hitboxState = 0;
        break;
    case 1:
        AnimateEntity(D_us_80180D7C, self);
        if (self->scaleX < 256) {
            self->scaleX = self->scaleY += 8;
        } else {
            self->scaleX = self->scaleY = 256;
            self->step++;
        }
        break;
    case 2:
        AnimateEntity(D_us_80180D7C, self);
        if (g_Timer % 12 == 0) {
            entity = AllocEntity(&g_Entities[160], &g_Entities[168]);
            if (entity != NULL) {
                CreateEntityFromEntity(E_ID(UNK_2F), self, entity);
                entity->ext.olroxAfterImage.parent = self;
                PlaySfxPositional(0x691);
            }
        }
        if (g_Timer % 5) {
            self->palette = 0x8213;
        } else {
            self->palette = 0x8215;
        }
        entity = self->ext.olroxAfterImage.parent;
        if (entity->ext.olroxAfterImage.unk85) {
            self->step++;
        }
        break;
    case 3:
        AnimateEntity(D_us_80180D7C, self);
        self->scaleX = self->scaleY -= 8;
        if (self->scaleX < 0) {
            DestroyEntity(self);
        }
        break;
    }
}

extern EInit D_us_801806D8;
extern u8 D_us_80180D38[];

void func_us_801AFAF4(Entity* self) {
    Entity* entity; // s0
    u8 angle2; // s8
    s32 distX; // s7
    s32 distY; // s6
    s32 posX; // s5
    s16 angle; // s4
    s16 offsetX; // s3
    s16 offsetY; // s2
    s32 distance; // s1

    entity = self->ext.olroxAfterImage.parent;
    if (entity->flags & FLAG_DEAD) {
        self->flags |= FLAG_DEAD;
    }
    if (self->flags & FLAG_DEAD) {
        entity = AllocEntity(&g_Entities[224], &g_Entities[256]);
        if (entity) {
            CreateEntityFromEntity(2, self, entity);
            entity->params = 2;
        }
        DestroyEntity(self);
        PlaySfxPositional(0x64E);
        return;
    }

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_801806D8);
        self->hitboxState = 0;
        self->hitboxOffX = 1;
        self->hitboxOffY = 1;
        entity = self->ext.olroxAfterImage.parent;
        self->zPriority = entity->zPriority + 2;
        self->palette = 0x219;
        self->pose = (Random() & 3) * 2;
        self->ext.olroxAfterImage.timer = (self->params + 1) * 14;
        self->drawFlags |= 3;
        self->params = Random() & 3;
        break;

    case 1:
        AnimateEntity(D_us_80180D38, self);
        posX = self->posX.i.hi;
        entity = self->ext.olroxAfterImage.parent;

        offsetX = entity->posX.i.hi;
        offsetY = entity->posY.i.hi;
        offsetY -= 32;

        distX = self->posX.i.hi - offsetX;
        distY = self->posY.i.hi - offsetY;
        
        angle = ratan2(-distY, distX);
        if (entity->facingLeft) {
            angle += ROT(45.0 / 32.0);
        } else {
            angle -= ROT(45.0 / 32.0);
        }

        distance = SQ(distX) + SQ(distY);
        distance = SquareRoot0(distance);
        distance -= 2;
        self->posX.i.hi = offsetX + (distance * rcos(angle)) / 4096;
        self->posY.i.hi = offsetY - (distance * rsin(angle) / 4096);
        self->scaleX = (distance * self->params) + 0x100;
        if (self->scaleX > 0x300) {
            self->scaleX = 0x300;
        }
        self->scaleY = self->scaleX;
        posX = self->posX.i.hi - posX;
        if (posX > 0) {
            self->facingLeft = false;
        } else {
            self->facingLeft = true;
        }
        if (distance < 8) {
            self->ext.ILLEGAL.u8[0x2C] = Random();
            self->palette = 0x209;
            self->hitboxState = 3;
            self->drawFlags = 0;
            self->step++;
        }
        break;

    case 2:
        entity = self->ext.olroxAfterImage.parent;
        AnimateEntity(D_us_80180D38, self);
        MoveEntity();
        if (self->velocityX > 0) {
            self->facingLeft = true;
            self->zPriority = entity->zPriority + 2;
        } else {
            self->facingLeft = false;
            self->zPriority = entity->zPriority - 2;
        }
        offsetX = entity->posX.i.hi;
        offsetY = entity->posY.i.hi;
        offsetX = offsetX - self->posX.i.hi;
        offsetY = offsetY - self->posY.i.hi;
        angle2 = Ratan2Shifted(offsetX, offsetY);
        self->ext.olroxAfterImage.unkA8 =
            AdjustValueWithinThreshold(2,
                                       self->ext.ILLEGAL.u8[0x2C],
                                       angle2);
        SetEntityVelocityFromAngle(self->ext.ILLEGAL.u8[0x2C], 0x10);
        if (entity->ext.olroxAfterImage.unk84) {
            if (!--self->ext.olroxAfterImage.timer) {
                entity = &PLAYER;
                angle2 = GetAngleBetweenEntitiesShifted(self, entity);
                SetEntityVelocityFromAngle(angle2, 32);
                self->step++;
            }
        }
        break;

    case 3:
        AnimateEntity(D_us_80180D38, self);
        MoveEntity();
        if (self->velocityX > 0) {
            self->facingLeft = false;
        } else {
            self->facingLeft = true;
        }

        if (abs(self->posX.i.hi) > 0x200 || abs(self->posY.i.hi) > 0x200) {
            DestroyEntity(self);
        }
        break;
    }
}

extern EInit g_EInitOlroxAfterImage;

void EntityOlroxAfterImage(Entity* self) {
    if (!self->step) {
        InitializeEntity(g_EInitOlroxAfterImage);
        self->hitboxState = 0;
        self->palette = 0x217;
        self->animCurFrame = self->params;
        self->drawFlags = 8;
        self->opacity = 0x80;
        self->blendMode = 0x30;
        self->zPriority -= 2;
    }
    self->opacity -= 2;
    if (!self->opacity) {
        DestroyEntity(self);
    }
}

INCLUDE_ASM("boss/bo0/nonmatchings/2D26C", func_us_801B001C);
