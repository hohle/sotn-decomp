// SPDX-License-Identifier: AGPL-3.0-or-later
#include "bo0.h"

s16 func_pspeu_09258DE0(s16 arg0, s16 arg1, s16 arg2) {
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

bool func_pspeu_09258EF0(s16 x, s16 y) {
    Collider collider;
    g_api.CheckCollision(x, y, &collider, 0);
    if (collider.effects & EFFECT_SOLID) {
        return true;
    } else {
        return false;
    }
}

INCLUDE_ASM("boss/bo0_psp/nonmatchings/bo0_psp/2D26C", func_us_801AD338);

INCLUDE_ASM("boss/bo0_psp/nonmatchings/bo0_psp/2D26C", func_pspeu_0925B1B0);

INCLUDE_ASM("boss/bo0_psp/nonmatchings/bo0_psp/2D26C", func_pspeu_0925C178);

// Skulls that come from the Portal
INCLUDE_ASM("boss/bo0_psp/nonmatchings/bo0_psp/2D26C", func_pspeu_0925C580);

extern u8 D_pspeu_0928FAC0[];
extern EInit g_EInitOlroxAfterImage;

void func_pspeu_0925C938(Entity* self) {
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
        AnimateEntity(D_pspeu_0928FAC0, self);
        if (self->scaleX < 256) {
            self->scaleX = self->scaleY += 8;
        } else {
            self->scaleX = self->scaleY = 256;
            self->step++;
        }
        break;
    case 2:
        AnimateEntity(D_pspeu_0928FAC0, self);
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
        AnimateEntity(D_pspeu_0928FAC0, self);
        self->scaleX = self->scaleY -= 8;
        if (self->scaleX < 0) {
            DestroyEntity(self);
        }
        break;
    }
}

extern EInit D_pspeu_09275F50;
extern u8 D_pspeu_0928FA78[];

void func_pspeu_0925CBE8(Entity* self) {
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
        InitializeEntity(D_pspeu_09275F50);
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
        AnimateEntity(D_pspeu_0928FA78, self);
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
        AnimateEntity(D_pspeu_0928FA78, self);
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
        AnimateEntity(D_pspeu_0928FA78, self);
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

INCLUDE_ASM("boss/bo0_psp/nonmatchings/bo0_psp/2D26C", func_us_801B001C);
