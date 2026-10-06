// SPDX-License-Identifier: AGPL-3.0-or-later
#include "bo0.h"

typedef struct OlroxTrueForm {
    /* 0x00 */ u32 : 32; // probably pointer
#ifdef VERSION_PSP
    u32 : 32;
#endif
    /* 0x04 */ u32 : 32;
    /* 0x08 */ u32 : 32;
    /* 0x0C */ f32 angle; // angle?
    /* 0x10 */ f32 angle2;
    /* 0x14 */ s32 unk18;
    /* 0x18 */ struct OlroxTrueForm* next;
    /* 0x1C */ f32 posX;
    /* 0x20 */ f32 posY;
    /* 0x24 */ u8 step;
    /* 0x25 */ u8 : 8;
    /* 0x26 */ u16 hitKind;
    /* 0x28 */ f32 offsetX;
    /* 0x2C */ f32 offsetY;
} OlroxTrueForm; // size=0x30

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B13A8);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1590);

#include "../../st/approach_s16.h"

static bool func_us_801B163C(s16* arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;
    s16 y;
    s32 temp_s4;
    s32 var_s1;
    s16* var_s2;

    var_s2 = arg0 + 1;
    var_s1 = arg2 / 16;
    if (var_s1 == 0) {
        var_s1 = 1;
    }
    temp_v0 = arg1 - *arg0;
    y = *var_s2;
    if (temp_v0 > 0) {
        if (y < arg2) {
            y += var_s1;
        } else {
            y -= var_s1;
        }
    } else if (y > -arg2) {
        y -= var_s1;
    } else {
        y += var_s1;
    }
    temp_s4 = abs(temp_v0);
    if (temp_s4 < abs(y)) {
        *arg0 = arg1;
        *var_s2 = temp_v0;
        return true;
    }
    *arg0 += y;
    *var_s2 = y;
    return false;
}

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B171C);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B17BC);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1864);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1950);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B19FC);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1B30);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1C60);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1CE0);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1DDC);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1E5C);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1EDC);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B1F5C);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B2044);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B20F4);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B2178);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B21F0);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B24CC);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B2690);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B30AC);

// Entity update - True Form logic?
INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B365C);

// Entity update - Leg?
INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B5470);

// Entity update - Head
INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B551C);

static u8 func_us_801B5D6C(s16* arg0, s16* arg1, s16 arg2);
INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B5D6C);

static u8 func_us_801B5E08(s16* arg0, s16* arg1, s16 arg2) {
    s32 i;
    u8 notFound;

    notFound = true;
    for (i = 0; i < 8; i++, arg0++, arg1++) {
        if (!func_us_801B163C(arg0, *arg1, arg2)) {
            notFound = false;
        }
        arg0++;
    }
    return notFound;
}

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B5E8C);

extern EInit D_us_80180708;
extern s16 D_us_80181288[];
extern s16 D_us_80181298[];
extern s16 D_us_801812A8[];
extern s16 D_us_801812B8[];
extern s16* D_us_801812D0[];
extern bool D_us_801CE5B0;

void EntityTrueFormTail(Entity* self) {
    s32 i;
    Entity* parent;
    Primitive* prim;
    s32 primIndex;
    s16* var_v0_2;
    u8 notFound;

    parent = self - 4;
    self->facingLeft = parent->facingLeft;
    self->palette = parent->palette;
    if (!D_us_801CE5B0) {
        self->posX.val = parent->posX.val;
        self->posY.val = parent->posY.val;
        if (!self->facingLeft) {
            self->posX.i.hi += 4;
        } else {
            self->posX.i.hi -= 4;
        }
    }
    if (self->flags & FLAG_DEAD) {
        self->hitboxState = 0;
    }
    switch (self->step) {
    case 0:
        InitializeEntity(D_us_80180708);
        self->hitboxState = 0;
        self->animCurFrame = 0;
        self->flags |= FLAG_POS_CAMERA_LOCKED;
        primIndex = g_api.AllocPrimitives(PRIM_GT4, 8);
        if (primIndex == -1) {
            self->step = 0;
        } else {
            self->flags |= FLAG_HAS_PRIMS;
            self->primIndex = primIndex;
            prim = &g_PrimBuf[primIndex];
            self->ext.prim = prim;
            for (i = 0; i < 8; i++) {
                prim->tpage = 0x14;
                prim->clut = 0x20B;
                prim->u0 = prim->u2 = i * 11 + 128;
                prim->u1 = prim->u3 = prim->u0 + 11;
                prim->v0 = prim->v1 = 0x50;
                prim->v2 = prim->v3 = 0x60;
                prim->priority = 0xA1;
                prim->drawMode = DRAW_UNK02;
                prim = prim->next;
            }
            var_v0_2 = (s16*)&self->ext.olroxTrueForm.unk88;
            for (i = 0; i < 8; i++, var_v0_2++) {
                *var_v0_2 = -0x180;
                var_v0_2++;
            }
            self->ext.ILLEGAL.u16[4] = 0;
        case 1:
            if (!D_us_801CE5B0) {
                self->step++;
            }
        }
        break;
    case 2:

        if (self->ext.olroxTrueForm.unk84 < 0x1000) {
            self->ext.olroxTrueForm.unk84 += 0x200;
        } else {
            self->ext.olroxTrueForm.unk84 = 0x1000;
            self->step++;
        }
        break;

    case 3:
        notFound = func_us_801B5E08(
            self->ext.olroxTrueForm.unk88,
            D_us_801812D0[self->ext.olroxTrueForm.unk80], 0x20);
        if (notFound) {
            self->ext.olroxTrueForm.unk80 ^= 1;
        }
        break;
    case 4:
        func_us_801B5E08(self->ext.olroxTrueForm.unk88, D_us_80181288, 0x20);
        break;
    case 6:
        func_us_801B5E08(self->ext.olroxTrueForm.unk88, D_us_80181298, 0x60);
        break;
    case 7:
        func_us_801B5E08(self->ext.olroxTrueForm.unk88, D_us_801812A8, 0x80);
        break;
    case 8:
        func_us_801B5E08(self->ext.olroxTrueForm.unk88, D_us_801812B8, 0x60);
        break;
    case 9:
        notFound = func_us_801B5D6C(
            self->ext.olroxTrueForm.unk88,
            D_us_801812D0[self->ext.olroxTrueForm.unk80], 0x40);
        if (notFound) {
            self->ext.olroxTrueForm.unk80 ^= 1;
        }
        break;
    }
    func_us_801B5E8C();
    if (self->palette & PAL_UNK_FLAG) {
        prim = self->ext.prim;
        while (prim != NULL) {
            prim->clut = self->palette & 0xFFF;
            prim = prim->next;
        }
    }
    parent = self - 4;
    if (parent->ext.ILLEGAL.u8[31]) {
        prim = self->ext.prim;
        while (prim != NULL) {
            prim->tpage = 0x15;
            prim->clut = 0x219;
            prim = prim->next;
        }
    }
}

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B6520);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B65C0);

// Entity update - Arms
INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B6CA4);

extern EInit D_us_80180708;
extern s32 D_us_801CE56C;

void EntityTrueFormHands(Entity* self) {
    Entity* parent;
    Primitive* prim;
    s32 primIndex;
    s32 posX, posY;

    if (self->params) {
        parent = self - 8;
    } else {
        parent = self - 9;
    }
    self->facingLeft = parent->facingLeft;
    if (parent->palette & PAL_UNK_FLAG) {
        self->palette = parent->palette;
    } else if (!(self->flags & 0xF)) {
        self->palette = 0x20B;
    }
    if (self->flags & FLAG_DEAD) {
        self->hitboxState = 0;
    }

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_80180708);
        self->hitPoints = 0x80;
        self->hitboxWidth = 0xC;
        self->hitboxHeight = 6;
        self->parent = NULL;
        self->drawFlags |= ENTITY_ROTATE;
        if (self->params) {
            self->zPriority = D_us_801CE56C - 4;
            self->animCurFrame = 0x20;
        } else {
            self->zPriority = D_us_801CE56C + 2;
            self->animCurFrame = 0x1F;
        }
        break;

    case 1: /* switch 1 */
        if (self->flags & FLAG_DEAD) {
            self->hitboxState = 0;
            self->step = 2;
            self->step_s = 0;
        }
        break;
    case 2:                     /* switch 1 */
        switch (self->step_s) { /* switch 2; irregular */
        case 0:                 /* switch 2 */
            MakeExplosions();
            self->animCurFrame = 0;
            0;
            self->drawFlags |= ENTITY_SCALEY | ENTITY_SCALEX;
            self->flags &= -0x100;
            self->scaleX = self->scaleY = 0;
            self->step_s++;
            self->ext.olroxTrueForm.unk94 = 0x100;
            break;
        case 1: /* switch 2 */
            if (!--self->ext.olroxTrueForm.unk94) {
                self->step_s++;
            }
            break;
        case 2: /* switch 2 */
            self->scaleY = self->scaleX += 2;
            if (self->scaleX > 0x100) {
                self->flags &= -0x101;
                self->hitPoints = 0x80;
                self->drawFlags = ENTITY_ROTATE;
                self->hitboxState = 3;
                self->palette = 0x20B;
                self->hitEffect = 0;
                self->step_s = 0;
                self->step = 1;
            }
            break;
        }
        break;
    case 3: /* switch 1 */
        self->drawFlags = ENTITY_ROTATE;
        switch (self->step_s) { /* switch 3; irregular */
        case 0:                 /* switch 3 */
            self->hitboxState = 0;
            primIndex = g_api.AllocPrimitives(PRIM_GT4, 1);
            if (primIndex == -1) {
                self->step_s = 2;
            } else {
                self->flags |= FLAG_HAS_PRIMS;
                self->primIndex = primIndex;
                prim = &g_PrimBuf[primIndex];
                self->ext.olroxTrueForm.prim = prim;
                func_us_801B13A8(prim);
                posX = self->posX.i.hi;
                posY = self->posY.i.hi;
                g_api.func_800EB758(posX, posY, self, self->drawFlags,
                                    (POLY_GT4*)prim, self->facingLeft);
                prim->tpage = 0x14;
                prim->clut += 0x20B;
                prim->priority = self->zPriority;
                prim->drawMode = DRAW_UNK02;
                self->step_s++;
            }
            break;
        case 1: /* switch 3 */
            self->palette = 0x219;
            self->unk5A = 0x54;
            if (self->params) {
                parent = self - 8;
            } else {
                parent = self - 9;
            }
            if (parent->ext.olroxTrueForm.unk9B) {
                prim = self->ext.olroxTrueForm.prim;
                prim->drawMode = DRAW_HIDE;
                self->step_s++;
            }
            break;
        case 2: /* switch 3 */
            self->palette = PAL_FLAG(0x219);
            self->unk5A = 0x54;
            if (self->params) {
                parent = self - 8;
            } else {
                parent = self - 9;
            }
            if (parent->ext.olroxTrueForm.unk9B == 3) {
                prim = self->ext.olroxTrueForm.prim;
                func_us_801B13A8(prim);
                posX = self->posX.i.hi;
                posY = self->posY.i.hi;
                g_api.func_800EB758(posX, posY, self, self->drawFlags,
                                    (POLY_GT4*)prim, self->facingLeft);
                prim->tpage = 0x15;
                prim->clut = 0x219;
                prim->priority = self->zPriority;
                prim->drawMode = DRAW_UNK02;
                self->step_s++;
            }
            break;
        }
        break;
    }
    if (self->params) {
        self->zPriority = D_us_801CE56C - 4;
        parent = self - 8;
    } else {
        self->zPriority = D_us_801CE56C + 2;
        parent = self - 9;
    }
    if (parent->flags & FLAG_DEAD) {
        self->hitboxState = 0;
    }
    self->hitboxOffX = -(FLT_TO_I(rcos(self->rotate - 0x100) * 0xA));
    self->hitboxOffY = -(FLT_TO_I(rsin(self->rotate - 0x100) * 0xA));
}

// Entity update
INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B7BAC);

INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B7C44);

// Entity update - death animation
INCLUDE_ASM("boss/bo0/nonmatchings/313A8", func_us_801B7CC8);
