// SPDX-License-Identifier: AGPL-3.0-or-later
#include "no1.h"

extern u16 D_us_80180A1C[];
extern s16 D_us_80181508[][3];
extern s16 D_us_8018151C[][3];

void func_us_801BB984(Entity* self) {
    Primitive* prim;
    s32 primIndex;
    s16 dx;
    s32 i;
    Entity* tempEntity;
    u8 params;
    s32 tilePos;

    params = self->params;
    tempEntity = &g_Entities[152];

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_80180A1C);
        self->animCurFrame = 0x1F;
        primIndex = g_api.AllocPrimitives(PRIM_GT4, 2);
        if (primIndex != -1) {
            self->flags |= FLAG_HAS_PRIMS;
            self->primIndex = primIndex;
            prim = &g_PrimBuf[primIndex];
            self->ext.et_801BBD90.unk7C = prim;
            for (i = 0; prim != NULL; i++) {
                prim->tpage = 0x12;
                prim->clut = 0x209;
                prim->u0 = prim->u2 = 0x70;
                prim->u1 = prim->u3 = 0x7D;
                prim->x0 = prim->x2 = self->posX.i.hi - 0xC;
                prim->x1 = prim->x3 = prim->x0 + 0xD;
                if (i == 0) {
                    prim->v0 = prim->v1 = 0xCC;
                    prim->v2 = prim->v0 + 0x22;
                    prim->v3 = prim->v0 + 0x14;
                    prim->y0 = prim->y1 = self->posY.i.hi - 0x18;
                    prim->y2 = prim->y0 + 0x22;
                    prim->y3 = prim->y0 + 0x14;
                } else {
                    prim->v0 = 0xEE;
                    prim->v1 = 0xE0;
                    prim->v2 = prim->v3 = 0xFC;
                    prim->y2 = prim->y3 = self->posY.i.hi + 0x18;
                    prim->y0 = prim->y2 - 0xE;
                    prim->y1 = prim->y2 - 0x1C;
                }
                prim->priority = 0x69;
                prim->drawMode = DRAW_UNK02;
                prim = prim->next;
            }
            self->animSet = 0;
        } else {
            self->ext.et_801BBD90.unk7C = NULL;
        }
        break;

    case 1:
        if (g_CastleFlags[CASTLE_FLAG_16]) {
            if (tempEntity->ext.et_801BBD90.unk84 == params &&
                tempEntity->ext.et_801BBD90.unk85 == params) {
                SetStep(2);
            }
            tempEntity = &PLAYER;
            dx = self->posX.i.hi - tempEntity->posX.i.hi;
            if (dx < 0) {
                self->ext.et_801BBD90.unk88 = 0x20;
            } else if ((dx < 0x20) && (GetDistanceToPlayerY() < 0x10)) {
                if (!--self->ext.et_801BBD90.unk88) {
                    self->step = 4;
                }
            } else {
                self->ext.et_801BBD90.unk88 = 0x20;
            }
        }
        break;

    case 2:
        self->animCurFrame = 0;
        if (tempEntity->ext.et_801BBD90.unk85 != params) {
            self->step_s = 0;
            self->step = 3;
        }
        break;

    case 3:
        self->animCurFrame = 0x1F;
        self->step_s = 0;
        self->step = 1;
        break;

    case 4:
        switch (self->step_s) {
        case 0:
            tempEntity->ext.et_801BBD90.unk94 = 1;
            tempEntity->ext.et_801BBD90.unk85 = params;
            self->step_s++;
            /* fallthrough */
        case 1:
            if (tempEntity->ext.et_801BBD90.unk84 == params) {
                self->step_s = 0;
                self->step = 2;
            }
            break;
        }
        break;
    }
    if (self->ext.et_801BBD90.unk7C != NULL) {
        if (self->animCurFrame) {
            func_us_801BB5E0();
        } else {
            func_us_801BB7B8();
        }
    }
    if (self->animCurFrame) {
        for (i = 0; i < 3; i++) {
            tilePos = D_us_80181508[params][i];
            g_Tilemap.fg[tilePos] = D_us_8018151C[params][i];
        }
    } else {
        for (i = 0; i < 3; i++) {
            tilePos = D_us_80181508[params][i];
            g_Tilemap.fg[tilePos] = D_us_8018151C[params + 3][i];
        }
    }
}
