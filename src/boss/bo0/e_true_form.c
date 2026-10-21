// SPDX-License-Identifier: AGPL-3.0-or-later
#include "bo0.h"

#include <scratchpad.h>

s32 D_us_80181190 = 0;

extern s16* D_us_801A5ED4[];

static void func_us_801B13A8(Primitive* prim) {
    s16 posY;
    s16 posX;
    s16 posU;
    s16 posV;
    s16 offsetX;
    s16 offsetY;
    s16* var_s0;

    var_s0 = D_us_801A5ED4[g_CurrentEntity->animCurFrame];
    var_s0 += 2;

    posU = (g_CurrentEntity->unk5A & 1);
    posU = posU * 127;
    posV = ((g_CurrentEntity->unk5A & 2) >> 1);
    posV = posV * 127;

    posX = g_CurrentEntity->posX.i.hi;
    if (g_CurrentEntity->facingLeft) {
        posX -= *var_s0++;
    } else {
        posX += *var_s0++;
    }
    posY = g_CurrentEntity->posY.i.hi + *var_s0++;
    offsetX = *var_s0++;
    offsetY = *var_s0++;
    if (g_CurrentEntity->facingLeft) {
        prim->x0 = (posX - offsetX) + 1;
        prim->y0 = posY;
        prim->x1 = posX + 1;
        prim->y1 = posY;
        prim->x2 = (posX - offsetX) + 1;
        prim->y2 = posY + offsetY;
        prim->x3 = posX + 1;
        prim->y3 = posY + offsetY;
    } else {
        prim->x0 = posX;
        prim->y0 = posY;
        prim->x1 = posX + offsetX;
        prim->y1 = posY;
        prim->x2 = posX;
        prim->y2 = posY + offsetY;
        prim->x3 = posX + offsetX;
        prim->y3 = posY + offsetY;
    }

    prim->clut = *var_s0++;

    if (*var_s0 & 1) {
        posU += 127;
    }
    if (*var_s0 & 2) {
        posV += 127;
    }
    var_s0++;
    if (g_CurrentEntity->facingLeft) {
        prim->u1 = prim->u3 = posU + *var_s0++;
        prim->v0 = prim->v1 = posV + *var_s0++;
        prim->u0 = prim->u2 = posU + *var_s0++;
        prim->v2 = prim->v3 = posV + *var_s0++;
    } else {
        prim->u0 = prim->u2 = posU + *var_s0++;
        prim->v0 = prim->v1 = posV + *var_s0++;
        prim->u1 = prim->u3 = posU + *var_s0++;
        prim->v2 = prim->v3 = posV + *var_s0++;
    }
}

static void func_us_801B1590(u8 step) {
    OlroxTrueForm* trueForm;

    g_CurrentEntity->step = step;
    g_CurrentEntity->step_s = 0;

    trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm1;
    trueForm->step = 0;

    trueForm = trueForm->next;
    trueForm->step = 0;
}

#include "../../st/approach_s16.h"

typedef struct {
    s16 pos;
    s16 velocity;
} PositionVelocity;

/// approach a target with accelerating with a max velocity.
///
/// Params:
///    - posVel: a pair of s16s, current position and velocity
///    - target: the target position
///    - maxVelocity: the maximum velocity
static bool func_us_801B163C(s16* posVel, s16 target, s16 maxVelocity) {
    s16 distance;
    s16 newVelocity;
    s32 acceleration;
    s16* velocity;

    velocity = posVel + 1;
    acceleration = maxVelocity / 16;
    if (acceleration == 0) {
        acceleration = 1;
    }
    distance = target - *posVel;
    newVelocity = *velocity;
    if (distance > 0) {
        if (newVelocity < maxVelocity) {
            newVelocity += acceleration;
        } else {
            newVelocity -= acceleration;
        }
    } else if (newVelocity > -maxVelocity) {
        newVelocity -= acceleration;
    } else {
        newVelocity += acceleration;
    }

    // reached the target
    if (abs(distance) < abs(newVelocity)) {
        *posVel = target;
        *velocity = distance;
        return true;
    } else {
        *posVel += newVelocity;
        *velocity = newVelocity;
        return false;
    }
}

static s32 func_us_801B171C(
    OlroxTrueForm* trueForm, s16 target1, s16 target2, s16 treshold) {
    s32 i;
    s16* var_s0;
    s16* var_s1;
    s16 diff;
    s16 var_s3;
    bool retVal;

    retVal = 0;
    var_s0 = &trueForm->angle.i.lo;
    var_s1 = &trueForm->angle.i.hi;
    var_s3 = target1;
    for (i = 0; i < 2; i++) {
        diff = var_s3 - *var_s0;
        if (abs(diff) < treshold) {
            *var_s0 = var_s3;
            *var_s1 = diff;
        } else {
            if (diff > 0) {
                *var_s0 += treshold;
                *var_s1 = treshold;
            } else {
                *var_s0 -= treshold;
                *var_s1 = -treshold;
            }
            retVal |= true;
        }
        var_s0 = &trueForm->angle2.i.lo;
        var_s1 = &trueForm->angle2.i.hi;
        var_s3 = target2;
    }
    return retVal ^ 1;
}

static void func_us_801B17BC(OlroxTrueForm* trueForm) {
    switch (trueForm->step) {
    case 0:
        if (func_us_801B171C(trueForm, -0x400, 0x200, 0x18)) {
            trueForm->step++;
        }
        break;
    case 1:
        if (func_us_801B171C(trueForm, -0x400, -0x40, 0x20)) {
            trueForm->step++;
        }
        break;
    case 2:
        if (func_us_801B171C(trueForm, -0x300, -0x40, 0x20)) {
            trueForm->step++;
        }
        break;
    }
}

static void func_us_801B1864(OlroxTrueForm* trueForm) {
    switch (trueForm->step) {
    case 0:
        if (func_us_801B171C(trueForm, -0x40, 0x40, 0x1C)) {
            trueForm->step++;
        }

        if (g_CurrentEntity->ext.olroxTrueForm.unk88[4] > -256) {
            g_CurrentEntity->ext.olroxTrueForm.unk88[4] -= 12;
        }
        break;
    case 1:
        if (func_us_801B171C(trueForm, -0x100, 0x300, 0x18) != 0) {
            trueForm->step++;
        }

        if (g_CurrentEntity->ext.olroxTrueForm.unk88[4] < 0x100) {
            g_CurrentEntity->ext.olroxTrueForm.unk88[4] += 8;
        }
        break;
    }
}

static void func_us_801B1950(OlroxTrueForm* trueForm) {
    switch (trueForm->step) {
    case 0:
        if (func_us_801B171C(trueForm, -0x200, 0x300, 0x18)) {
            trueForm->step++;
        }
        break;
    case 1:
        if (func_us_801B171C(trueForm, 0, 0x280, 0x1C)) {
            trueForm->step++;
        }
        break;
    case 2:
        if (func_us_801B171C(trueForm, 0x80, 0x180, 0x18)) {
            trueForm->step++;
        }
        break;
    }
}

static void func_us_801B19FC(OlroxTrueForm* trueForm) {
    switch (trueForm->step) {
    case 0:
        if (func_us_801B171C(trueForm, -0x80, 0x80, 0x1C)) {
            trueForm->step++;
        }

        if (g_CurrentEntity->ext.olroxTrueFormHead.angle > -256) {
            g_CurrentEntity->ext.olroxTrueFormHead.angle -= 0x10;
        }
        break;
    case 1:
        if (func_us_801B171C(trueForm, -0x100, 0, 0x18)) {
            trueForm->step++;
        }
        break;
    case 2:
        if (func_us_801B171C(trueForm, -0x280, -0xC0, 0x14)) {
            trueForm->step++;
        }

        if (g_CurrentEntity->ext.olroxTrueFormHead.angle < 0x100) {
            g_CurrentEntity->ext.olroxTrueFormHead.angle += 0x10;
        }
        break;
    }
}

static s32 func_us_801B1B30(OlroxTrueForm* trueForm) {
    OlroxTrueForm* next;
    s32 complete;

    next = trueForm->next;

    switch (trueForm->step) {
    case 0:
        complete = func_us_801B171C(trueForm, -0x180, 0, 0x20);
        complete += func_us_801B171C(next, 0x80, 0x280, 0x20);
        if (complete == 2) {
            trueForm->step++;
        }
        break;
    case 1:
        complete = func_us_801B171C(trueForm, -0x200, -0x100, 0x40);
        func_us_801B171C(next, -0x100, 0x280, 0x40);

        if (complete != 0) {
            trueForm->step++;
        }
        break;
    case 2:
        complete = func_us_801B171C(trueForm, -0x280, -0x200, 0x60);
        func_us_801B171C(next, -0x180, 0x300, 0x40);

        if (complete != 0) {
            return true;
        }
        break;
    }

    return false;
}

static bool func_us_801B1C60(OlroxTrueForm* trueForm) {
    OlroxTrueForm* next;
    s32 temp_s0;

    next = trueForm->next;
    func_us_801B163C(
        &g_CurrentEntity->ext.olroxTrueFormHead.angle, -0x100, 0xC);
    temp_s0 = func_us_801B171C(trueForm, -0x1C0, 0x280, 0x10);
    temp_s0 += func_us_801B171C(next, -0x380, 0x140, 0x10);
    if (temp_s0 == 2) {
        return true;
    } else {
        return false;
    }
}

static bool func_us_801B1CE0(OlroxTrueForm* trueForm) {
    OlroxTrueForm* next;
    s32 count;

    next = trueForm->next;
    count = func_us_801B163C(
        &g_CurrentEntity->ext.olroxTrueFormHead.angle, 0x180, 0x40);

    switch (trueForm->step) {
    case 0:
        count += func_us_801B171C(trueForm, -0x60, 0x340, 0x18);
        if (func_us_801B171C(next, -0x500, 0x80, 0x20)) {
            trueForm->step++;
        }
        break;

    case 1:
        count += func_us_801B171C(trueForm, -0x40, 0x340, 0x18);
        count += func_us_801B171C(next, -0x3C0, 0xE0, 0x20);

        if (count == 3) {
            return true;
        }
        break;
    }
    return false;
}

static bool func_us_801B1DDC(OlroxTrueForm* trueForm) {
    OlroxTrueForm* next;
    s32 temp_s0;

    next = trueForm->next;
    func_us_801B163C(&g_CurrentEntity->ext.olroxTrueFormHead.angle, 0, 12);
    temp_s0 = func_us_801B171C(trueForm, -0x2C0, 0x2C0, 0x28);
    temp_s0 += func_us_801B171C(next, -0x100, 0x3C0, 0x38);
    if (temp_s0 == 2) {
        return true;
    } else {
        return false;
    }
}

static bool func_us_801B1E5C(OlroxTrueForm* trueForm) {
    OlroxTrueForm* next;
    s32 temp_s0;

    next = trueForm->next;
    func_us_801B163C(&g_CurrentEntity->ext.olroxTrueFormHead.angle, 0, 12);
    temp_s0 = func_us_801B171C(trueForm, -0x40, 0x40, 0x60);
    temp_s0 += func_us_801B171C(next, -0x200, 0x280, 0x50);
    if (temp_s0 == 2) {
        return true;
    } else {
        return false;
    }
}

static bool func_us_801B1EDC(OlroxTrueForm* trueForm) {
    OlroxTrueForm* next;
    s32 temp_s0;

    next = trueForm->next;
    func_us_801B163C(&g_CurrentEntity->ext.olroxTrueFormHead.angle, 0, 16);
    temp_s0 = func_us_801B171C(trueForm, -0x200, 0x200, 0x60);
    temp_s0 += func_us_801B171C(next, -0x200, 0x180, 0x40);
    if (temp_s0 == 2) {
        return true;
    } else {
        return false;
    }
}

static bool func_us_801B1F5C(OlroxTrueForm* arg0) {
    OlroxTrueForm* next;
    s32 temp_s0;

    next = arg0->next;
    switch (arg0->step) {
    case 0:
        temp_s0 = func_us_801B171C(arg0, -0x80, 0x80, 0x20);
        temp_s0 += func_us_801B171C(next, 0, 0x180, 0xC);
        if (temp_s0 == 2) {
            arg0->step++;
        }
        break;
    case 1:
        temp_s0 = func_us_801B171C(arg0, -0x300, 0, 0x28);
        temp_s0 += func_us_801B171C(next, 0x80, 0x100, 0xC);
        if (temp_s0 == 2) {
            return true;
        }
        break;
    }
    return false;
}

static void func_us_801B2044(OlroxTrueForm* olrox) {
    switch (olrox->step) {
    case 0:
        if (func_us_801B171C(olrox, -0x400, 0x200, 8)) {
            olrox->step++;
        }
        break;
    case 1:
        if (func_us_801B171C(olrox, -0x400, -0x40, 8)) {
            olrox->step++;
        }
        break;
    case 2:
        if (func_us_801B171C(olrox, -0x300, -0x40, 0xC)) {
            olrox->step++;
        }
        break;
    }
}

static void func_us_801B20F4(OlroxTrueForm* trueForm) {
    switch (trueForm->step) {
    case 0:
        if (func_us_801B171C(trueForm, -64, 64, 8)) {
            trueForm->step++;
        }
        break;
    case 1:
        if (func_us_801B171C(trueForm, -256, 0x380, 20)) {
            trueForm->step++;
        }
        break;
    }
}

static s16 func_us_801B2178(OlroxTrueForm* unkOlrox) {
    s16 offsetY;
    u16 hitKind;

    offsetY = g_Tilemap.scrollY.i.hi + unkOlrox->posY.i.hi;
    if (offsetY >= 0x1CC) {
        offsetY = 0x1CC - offsetY;
        hitKind = 1;
    } else {
        offsetY = 0;
        hitKind = 0;
    }
    unkOlrox->hitKind = hitKind;
    FntPrint("hit_kind %x\n", hitKind);
    return offsetY;
}

static void func_us_801B21F0(void) {
    s32 targetX;
    s32 targetY;
    s32 offsetX;
    s32 offsetY;
    s32 posX;
    s32 posY;
    s16 angle2;
    s16 angle;
    OlroxTrueForm* trueForm;
    Entity* entity;
    Entity* entity2;

    entity = g_CurrentEntity + 1;
    entity2 = g_CurrentEntity + 2;
    trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm1;
    trueForm->posX.val = entity->posX.val;
    trueForm->posY.val = entity->posY.val;

    trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm2;
    trueForm->posX.val = entity2->posX.val;
    trueForm->posY.val = entity2->posY.val;
    ;

    if (g_CurrentEntity->ext.olrox.unk88 == 0) {
        trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm1;
    } else {
        trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm2;
    }

    posX = trueForm->posX.val;
    posY = trueForm->posY.val;
    if (g_CurrentEntity->facingLeft) {
        angle = FLT(0.75) - trueForm->angle2.i.lo;
    } else {
        angle = trueForm->angle2.i.lo + FLT(0.75);
    }
    offsetX = posX - ((rcos(angle) * 0x2A) << 4);
    offsetY = posY + ((rsin(angle) * 0x2A) << 4);
    trueForm->offsetX.val = offsetX;
    trueForm->offsetY.val = offsetY;

    if (g_CurrentEntity->facingLeft) {
        angle2 = FLT(0.75) - trueForm->angle.i.lo;
    } else {
        angle2 = trueForm->angle.i.lo + FLT(0.75);
    }
    targetX = offsetX - ((rcos(angle2) * 0x1C) << 4);
    targetY = offsetY + ((rsin(angle2) * 0x1C) << 4);
    trueForm->unk14 = (posX - targetX);
    if (!g_CurrentEntity->facingLeft) {
        trueForm->unk14 = -trueForm->unk14;
    }
    g_CurrentEntity->posX.val = targetX;
    g_CurrentEntity->posY.val = targetY + FIX(-4);
    trueForm = trueForm->next;
    if (g_CurrentEntity->facingLeft) {
        angle2 = FLT(0.75) - trueForm->angle.i.lo;
    } else {
        angle2 = trueForm->angle.i.lo + FLT(0.75);
    }
    offsetX = targetX + ((rcos(angle2) * 28) << 4);
    offsetY = targetY - ((rsin(angle2) * 0x1C) << 4);
    trueForm->offsetX.val = offsetX;
    trueForm->offsetY.val = offsetY;
    if (g_CurrentEntity->facingLeft) {
        angle = FLT(0.75) - trueForm->angle2.i.lo;
    } else {
        angle = trueForm->angle2.i.lo + FLT(0.75);
    }
    posX = offsetX + ((rcos(angle) * 0x2A) << 4);
    posY = offsetY - ((rsin(angle) * 0x2A) << 4);
    trueForm->posX.val = posX;
    trueForm->posY.val = posY;
    trueForm->unk14 = (targetX - posX);
    if (g_CurrentEntity->facingLeft) {
        trueForm->unk14 = -trueForm->unk14;
    }
}

static void func_us_801B24CC(void) {
    s32 i;
    s32 posX;
    s32 posY;
    s32 temp_s2;
    s32 posY_2;
    s16 angle;
    s16 angle2;
    Entity* entity1;
    Entity* entity2;
    OlroxTrueForm* trueForm;

    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v1;
    u32 temp_s1_2;

    entity1 = g_CurrentEntity + 1;
    entity2 = g_CurrentEntity + 2;

    trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm1;
    trueForm->posX.val = entity1->posX.val;
    trueForm->posY.val = entity1->posY.val;

    trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm2;
    trueForm->posX.val = entity2->posX.val;
    trueForm->posY.val = entity2->posY.val;

    trueForm = g_CurrentEntity->ext.olroxTrueFormHand.trueForm1;
    for (i = 0; i < 2; i++) {
        posX = g_CurrentEntity->posX.val;
        posY = g_CurrentEntity->posY.val;
        if (g_CurrentEntity->facingLeft) {
            angle = 0xC00 - trueForm->angle.i.lo;
        } else {
            angle = trueForm->angle.i.lo + 0xC00;
        }
        temp_s2 = posX + (rcos(angle) * 0x1C * 16);
        posY_2 = posY - (rsin(angle) * 0x1C * 16);
        trueForm->offsetX.val = temp_s2;
        trueForm->offsetY.val = posY_2;
        if (g_CurrentEntity->facingLeft) {
            angle2 = 0xC00 - trueForm->angle2.i.lo;
        } else {
            angle2 = trueForm->angle2.i.lo + 0xC00;
        }
        temp_s0 = temp_s2 + (rcos(angle2) * 0x2A * 16);
        temp_v1 = posY_2 - (rsin(angle2) * 0x2A * 16);
        trueForm->posX.val = temp_s0;
        trueForm->posY.val = temp_v1;

        trueForm->unk14 = temp_s0 - posX;
        if (g_CurrentEntity->facingLeft) {
            trueForm->unk14 = -trueForm->unk14;
        }
        trueForm = trueForm->next;
    }
}

static s32 D_us_801CE56C;
extern s32 D_us_801CE5B0;

static Primitive* func_us_801B2690(
    OlroxTrueForm* trueForm, Primitive* prim, u8 side) {
    u16 clut;
    s16 sp5C;
    s16 scrollY;
    s16 x_sp58;
    s16 x_sp56;
    s16 x_sp54;
    s16 x_s7;
    s16 x_s6;
    s16 y_sp52;
    s16 y_sp50;
    s16 y_sp4E;
    s16 var_s5;
    s32 offsetX;
    s32 offsetY;
    s32 posX;
    s32 posY;
    s32 entityPosX;
    s32 entityPosY;
    s16 trueFormAngle;
    s16 trueFormAngle2;
    s16 rotation;
    s16 angle;
    s16 sp4A;
    s16 sp48;
    s16 x_s4;
    s16 y_s3;
    s16 y_s1;

    if (D_us_801CE5B0 == 0) {
        scrollY = g_Tilemap.scrollY.i.hi;
    } else {
        scrollY = 0xE0;
    }
    if (side) {
        clut = 0x20B;
    } else {
        clut = 0x218;
    }

    side *= 2;

    entityPosX = g_CurrentEntity->posX.i.hi;
    entityPosY = g_CurrentEntity->posY.i.hi + 4;
    offsetX = trueForm->offsetX.i.hi;
    offsetY = trueForm->offsetY.i.hi;
    posX = trueForm->posX.i.hi;
    posY = trueForm->posY.i.hi;
    trueFormAngle = trueForm->angle.i.lo;
    if (g_CurrentEntity->facingLeft) {
        trueFormAngle = -trueFormAngle;
    } else {
        trueFormAngle += 0x800;
    }
    trueFormAngle2 = trueForm->angle2.i.lo;
    if (g_CurrentEntity->facingLeft) {
        trueFormAngle2 = -trueFormAngle2;
    } else {
        trueFormAngle2 += 0x800;
    }

    sp4A = trueFormAngle + (trueFormAngle2 - trueFormAngle) / 2;
    x_sp54 = FLT_TO_I(rcos(trueFormAngle) * 0xC);
    x_s6 = -x_sp54;
    y_sp4E = FLT_TO_I(-(rsin(trueFormAngle) * 0xC));
    var_s5 = -y_sp4E;

    x_sp54 += entityPosX;
    y_sp4E += entityPosY;
    x_s6 += entityPosX;
    var_s5 += entityPosY;

    x_sp56 = x_s4 = offsetX;
    y_sp50 = y_s1 = offsetY;
    if (!g_CurrentEntity->facingLeft) {
        angle = (trueFormAngle + 0x800) - trueFormAngle2;
        if (angle > 0x400) {
            angle = 0x400;
        }
    } else {
        angle = (trueForm->angle.i.lo + 0x800) - trueForm->angle2.i.lo;
        if (angle > 0x400) {
            angle = 0x400;
        }
    }
    sp48 = 12;
    sp48 += FLT_TO_I(rcos(angle) * 0x18);
    x_sp56 += FLT_TO_I(rcos(sp4A) * 0xC);
    y_sp50 += FLT_TO_I(-(rsin(sp4A) * 0xC));
    x_s4 -= FLT_TO_I(sp48 * rcos(sp4A));
    y_s1 -= FLT_TO_I(-(sp48 * rsin(sp4A)));
    x_sp58 = x_s7 = posX;
    y_sp52 = y_s3 = posY;
    x_sp58 += FLT_TO_I(rcos(trueFormAngle2) * 6);
    y_sp52 += FLT_TO_I(-(rsin(trueFormAngle2) * 6));
    x_s7 += FLT_TO_I(-(rcos(trueFormAngle2) * 6));
    y_s3 += FLT_TO_I(rsin(trueFormAngle2) * 6);
    prim->tpage = 0x14;
    prim->clut = clut;
    prim->u0 = 0x4C;
    prim->u1 = 0x6C;
    prim->u2 = 0x5C;
    prim->u3 = 0x6C;
    prim->v0 = 0x72;
    prim->v1 = 0x64;
    prim->v2 = 0x80;
    prim->v3 = 0x80;
    prim->x0 = x_sp56;
    prim->x1 = x_sp54;
    prim->x2 = x_s4;
    prim->x3 = x_s6;
    prim->y0 = y_sp50;
    prim->y1 = y_sp4E;
    prim->y2 = y_s1;
    prim->y3 = var_s5;
    prim->priority = D_us_801CE56C + side;
    prim->drawMode = DRAW_UNK02;
    prim = prim->next;

    prim->tpage = 0x14;
    prim->clut = clut;
    prim->u0 = 0x74;
    prim->u1 = 0x68;
    prim->u2 = 0x80;
    prim->u3 = 0x76;
    prim->v0 = 0x4E;
    prim->v1 = 0x30;
    prim->v2 = 0x46;
    prim->v3 = 0x20;
    prim->x0 = x_sp58;
    prim->x1 = x_sp56;
    prim->x2 = x_s7;
    prim->x3 = x_s4;
    prim->y0 = y_sp52;
    prim->y1 = y_sp50;
    prim->y2 = y_s3;
    prim->y3 = y_s1;
    prim->priority = D_us_801CE56C + side;
    prim->drawMode = DRAW_UNK02;
    prim = prim->next;

    angle = trueForm->angle2.i.lo;
    if (g_CurrentEntity->facingLeft) {
        angle = 0x800 - angle;
    }
    x_s6 = trueForm->posX.i.hi;
    var_s5 = trueForm->posY.i.hi;
    x_s6 += FLT_TO_I(rcos(angle) * 8);
    var_s5 += FLT_TO_I(-(rsin(angle) * 8));
    rotation = -0x400;
    if (g_CurrentEntity->facingLeft) {
        rotation = -rotation;
    }
    x_s6 += FLT_TO_I(rcos(angle + rotation) * 4);
    var_s5 += FLT_TO_I(-(rsin(angle + rotation) * 4));
    sp5C = var_s5 + scrollY;
    if (sp5C >= 0x1CE) {
        angle = 0;
        if (g_CurrentEntity->facingLeft) {
            angle = 0x800;
        }
        var_s5 = 0x1D0 - scrollY;
    }
    x_s4 = x_s6;
    y_s1 = var_s5;
    y_s1 -= FLT_TO_I(rsin(angle - 0x800) * 0x10);
    sp5C = y_s1 + scrollY;
    if (sp5C >= 0x1D0) {
        sp5C = var_s5 + scrollY;
        y_s1 = sp5C - 0x1D0;
        if (!g_CurrentEntity->facingLeft) {
            x_s4 -= SquareRoot0(SQ(16) - SQ(y_s1));
        } else {
            x_s4 += SquareRoot0(SQ(16) - SQ(y_s1));
        }
        angle = ratan2(-y_s1, x_s6 - x_s4);
        y_s1 = 0x1D0 - scrollY;
        rotation = 0x400;
        if (g_CurrentEntity->facingLeft) {
            rotation = -rotation;
        }

        x_sp54 = x_s6 + FLT_TO_I(rcos(angle + rotation) * 0x10);
        y_sp4E = var_s5 - FLT_TO_I(rsin(angle + rotation) * 0x10);
    } else {
        x_s4 += FLT_TO_I(rcos(angle - 0x800) * 0x10);
        rotation = 0x400;
        if (g_CurrentEntity->facingLeft) {
            rotation = -rotation;
        }

        x_sp54 = x_s6 + FLT_TO_I(rcos(angle + rotation) * 0x10);
        y_sp4E = var_s5 - FLT_TO_I(rsin(angle + rotation) * 0x10);
    }
    x_sp56 = x_s4;
    y_sp50 = y_s1;
    if (!g_CurrentEntity->facingLeft) {

        x_sp56 += FLT_TO_I(rcos(angle / 2 + 0x400) * 0x10);

        y_sp50 += FLT_TO_I(-(rsin(angle / 2 + 0x400) * 0x10));
    } else {

        x_sp56 += FLT_TO_I(rcos(angle / 2) * 0x10);
        y_sp50 += FLT_TO_I(-(rsin(angle / 2) * 0x10));
    }
    x_s7 = x_s4;
    y_s3 = y_s1;
    y_s3 -= FLT_TO_I(rsin(angle + 0x800) * 0x18);
    sp5C = y_s3 + scrollY;
    if (sp5C >= 0x1D0) {
        sp5C = y_s1 + scrollY;
        y_s3 = sp5C - 0x1D0;
        if (!g_CurrentEntity->facingLeft) {
            x_s7 -= SquareRoot0(SQ(24) - SQ(y_s3));
        } else {
            x_s7 += SquareRoot0(SQ(24) - SQ(y_s3));
        }
        angle = ratan2(-y_s3, x_s4 - x_s7);
        y_s3 = 0x1D0 - scrollY;
    } else {
        x_s7 += FLT_TO_I(rcos(angle + 0x800) * 0x18);
    }
    rotation = 0x400;
    if (g_CurrentEntity->facingLeft) {
        rotation = -rotation;
    }
    x_sp58 = x_s7 + FLT_TO_I(rcos(angle + rotation) * 0x10);
    y_sp52 = y_s3 + FLT_TO_I(-(rsin(angle + rotation) * 0x10));

    prim->tpage = 0x14;
    prim->clut = clut;
    prim->u0 = 0xD8;
    prim->u1 = 0xF0;
    prim->u2 = 0xD8;
    prim->u3 = 0xF0;
    prim->v0 = 0x50;
    prim->v1 = 0x50;
    prim->v2 = 0x5E;
    prim->v3 = 0x5E;
    prim->x0 = x_sp58;
    prim->x1 = x_sp56;
    prim->x2 = x_s7;
    prim->x3 = x_s4;
    prim->y0 = y_sp52;
    prim->y1 = y_sp50;
    prim->y2 = y_s3;
    prim->y3 = y_s1;
    prim->priority = D_us_801CE56C + 1 + side;
    prim->drawMode = DRAW_UNK02;
    prim = prim->next;

    prim->tpage = 0x14;
    prim->clut = clut;
    prim->u0 = 0xF0;
    prim->u1 = 0xFF;
    prim->u2 = 0xF0;
    prim->u3 = 0xFF;
    prim->v0 = 0x50;
    prim->v1 = 0x50;
    prim->v2 = 0x5E;
    prim->v3 = 0x5E;
    prim->x0 = x_sp56;
    prim->x1 = x_sp54;
    prim->x2 = x_s4;
    prim->x3 = x_s6;
    prim->y0 = y_sp50;
    prim->y1 = y_sp4E;
    prim->y2 = y_s1;
    prim->y3 = var_s5;
    prim->priority = D_us_801CE56C + 1 + side;
    prim->drawMode = DRAW_UNK02;
    prim = prim->next;

    return prim;
}

extern s16 D_us_80181194[][7];

static Primitive* func_us_801B30AC(Primitive* prim) {
    Entity* entity;
    s16* var_s0;

    s16 angle;
    s16 posX;
    s16 posY;
    s16 x_s5;
    s16 x_3e;
    s16 x3;
    s16 x2;
    s16 x1;
    s16 x0;
    s16 y1;
    s16 y_38;
    s16 y3;
    s16 y2;
    s16 y_32;
    s16 y0;

    posX = g_CurrentEntity->posX.i.hi;
    posY = g_CurrentEntity->posY.i.hi;
    var_s0 = D_us_80181194[g_CurrentEntity->ext.olroxTrueFormHand.unk89];
    if (!g_CurrentEntity->facingLeft) {
        posX += *var_s0++;
    } else {
        posX -= *var_s0++;
    }
    x1 = x0 = posX;
    y_32 = y0 = posY;

    if (!g_CurrentEntity->facingLeft) {
        x0 -= 32;
        x1 += 8;
    } else {
        x0 += 32;
        x1 -= 8;
    }
    angle = g_CurrentEntity->ext.olroxTrueFormHead.angle / 2;
    if (!g_CurrentEntity->facingLeft) {
        posX += FLT_TO_I(16 * rcos(angle + ROT(90)));
        posY += FLT_TO_I(-(16 * rsin(angle + ROT(90))));
    } else {
        angle = ROT(180) - angle;
        posX += FLT_TO_I(16 * rcos(angle - ROT(90)));
        posY += FLT_TO_I(-(16 * rsin(angle - ROT(90))));
    }
    x3 = x2 = posX;
    y3 = y2 = posY;

    x3 += FLT_TO_I(rcos(angle) * 8);
    y3 += FLT_TO_I(-(rsin(angle) * 8));
    x2 += FLT_TO_I(-(rcos(angle) * 32));
    y2 += FLT_TO_I(rsin(angle) * 32);

    angle = g_CurrentEntity->ext.olroxTrueFormHead.angle;
    if (!g_CurrentEntity->facingLeft) {
        posX += FLT_TO_I(32 * rcos(angle + ROT(90)));
        posY += FLT_TO_I(-(32 * rsin(angle + ROT(90))));
    } else {
        angle = ROT(180) - angle;
        posX += FLT_TO_I(rcos(angle - ROT(90)) * 32);
        posY += FLT_TO_I(-(rsin(angle - ROT(90)) * 32));
    }

    x_3e = x_s5 = posX;
    y_38 = y1 = posY;

    x_3e += FLT_TO_I(rcos(angle) * 8);
    y_38 += FLT_TO_I(-(rsin(angle) * 8));
    x_s5 += FLT_TO_I(-(rcos(angle) * 32));
    y1 += FLT_TO_I(rsin(angle) * 32);

    prim->tpage = 0x14;
    prim->clut = 0x20B;
    prim->u1 = prim->u3 = *var_s0;
    prim->u0 = prim->u2 = prim->u1 + 40;
    prim->v1 = prim->v0 = *(var_s0 + 1);
    prim->v3 = prim->v2 = prim->v1 + 32;
    prim->x0 = x_3e;
    prim->x1 = x_s5;
    prim->x2 = x3;
    prim->x3 = x2;
    prim->y0 = y_38;
    prim->y1 = y1;
    prim->y2 = y3;
    prim->y3 = y2;
    prim->priority = D_us_801CE56C - 1;
    prim->drawMode = DRAW_UNK02;
    prim = prim->next;

    prim->tpage = 0x14;
    prim->clut = 0x20B;
    prim->u1 = prim->u3 = var_s0[0];
    prim->u0 = prim->u2 = prim->u1 + 40;
    prim->v1 = prim->v0 = var_s0[1] + 32;
    prim->v3 = prim->v2 = prim->v1 + 16;
    prim->x0 = x3;
    prim->x1 = x2;
    prim->x2 = x1;
    prim->x3 = x0;
    prim->y0 = y3;
    prim->y1 = y2;
    prim->y2 = y_32;
    prim->y3 = y0;
    prim->priority = D_us_801CE56C - 1;
    prim->drawMode = DRAW_UNK02;
    prim = prim->next;

    angle = g_CurrentEntity->ext.olroxTrueFormHead.angle;

    var_s0 += 2;

    entity = g_CurrentEntity + 3;
    if (!g_CurrentEntity->facingLeft) {
        entity->posX.i.hi =
            x_s5 + FLT_TO_I(*(var_s0 + 0) * rcos(angle + *(var_s0 + 1)));
    } else {
        entity->posX.i.hi =
            x_s5 - FLT_TO_I(*(var_s0 + 0) * rcos(angle + *(var_s0 + 1)));
    }
    entity->posY.i.hi =
        y1 + FLT_TO_I(-(*(var_s0 + 0) * rsin(angle + *(var_s0 + 1))));

    if (g_CurrentEntity->ext.olroxTrueFormHand.unk89 == 2) {
        entity->zPriority = D_us_801CE56C - 1 + 1;
    } else {
        entity->zPriority = D_us_801CE56C - 1 - 1;
    }

    var_s0 += 2;

    entity = g_CurrentEntity + 7;
    if (!g_CurrentEntity->facingLeft) {
        entity->posX.i.hi =
            x_s5 + FLT_TO_I(*(var_s0 + 0) * rcos(angle + *(var_s0 + 1)));
    } else {
        entity->posX.i.hi =
            x_s5 - FLT_TO_I(*(var_s0 + 0) * rcos(angle + *(var_s0 + 1)));
    }
    entity->posY.i.hi =
        y1 + FLT_TO_I(-(*(var_s0 + 0) * rsin(angle + *(var_s0 + 1))));

    return prim;
}

// Entity update - True Form logic?
INCLUDE_ASM("boss/bo0/nonmatchings/e_true_form", func_us_801B365C);

extern EInit D_us_80180708;

// EntityTrueFormLeg
void func_us_801B5470(Entity* self) {
    OlroxTrueForm* trueForm;

    self->facingLeft = (self - 1)->facingLeft;
    if (self->flags & FLAG_DEAD) {
        self->hitboxState = 0;
    }

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_80180708);
        self->hitboxWidth = 0xC;
        self->hitboxHeight = 4;
        self->hitboxOffX = -0xC;
        self->animCurFrame = 0;
        break;
    case 1:
        trueForm = self->ext.olroxDeath.trueForm8C;
        self->posX.val = trueForm->posX.val;
        self->posY.val = trueForm->posY.val;
        break;
    }
}

extern s16 D_us_801811D0[];
extern s16 D_us_801811EC[];
extern s16 D_us_80181234[];
extern AnimateEntityFrame D_us_8018120C[];
extern AnimateEntityFrame D_us_80181220[];

// Entity update - Head
extern EInit D_us_80180714;
extern s32 D_us_801CE5B0;

void func_us_801B551C(Entity* self) {
    Primitive* prim;
    Entity* entity;
    s32 primIndex;
    s16 angle;
    s16 offsetX;
    s16 offsetY;
    s32 var_s6;
    s16* var_s2;

    entity = self - 3;
    self->facingLeft = entity->facingLeft;
    self->palette = entity->palette;
    if (self->flags & FLAG_DEAD) {
        self->hitboxState = 0;
    }

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_80180714);
        self->hitboxWidth = 0xA;
        self->hitboxHeight = 0xA;
        self->animCurFrame = 1;
        self->drawFlags |= ENTITY_ROTATE;
        self->zPriority = D_us_801CE56C - 2;
        self->rotate = ROT(-22.5);
        break;
    case 1:
        AnimateEntity(D_us_8018120C, self);
        func_801CDC80(&self->rotate, -0x80, 8);
        self->step_s = 0;
        break;
    case 7:
        AnimateEntity(D_us_80181220, self);
        func_801CDC80(&self->rotate, 0xC0, 8);
        if (!self->poseTimer) {
            if (!(self->pose % 4)) {
                g_api.PlaySfx(SFX_OLROX_MONSTER_PAIN);
            }
        }
        self->step_s = 0;
        break;
    case 6:
        self->animCurFrame = 1;
        func_801CDC80(&self->rotate, -0x100, 32);
        break;
    case 5:
        if (func_801CDC80(&self->rotate, 0x180, 16)) {
            if (!AnimateEntity(D_us_80181234, self)) {
                entity = self - 3;
                entity->ext.olroxTrueFormHead.unk99 = false;
                self->step = 1;
            }
            if ((self->pose == 2) && !self->poseTimer) {
                g_api.PlaySfx(SFX_OLROX_MONSTER_PAIN);
            }
            if (self->pose > 2) {
                if (self->poseTimer & 2) {
                    self->posX.i.hi++;
                } else {
                    self->posX.i.hi--;
                }
            }
        } else {
            self->pose = 0;
            self->poseTimer = 0;
        }
        break;
    case 2:
        self->animCurFrame = 2;
        var_s2 = D_us_801811D0;
#ifdef VERSION_PSP
        var_s2 += 2 + self->ext.olroxTrueFormHead.unkA8 * 4;
#else
        var_s2 += self->ext.olroxTrueFormHead.unkA8 * 4;
#endif
        if (func_801CDC80(&self->rotate, var_s2[0], 16)) {
            self->ext.olroxTrueFormHead.unkA9 = true;
            self->step = 3;
            self->step_s = 0;
        }
        break;
    case 3:
        switch (self->step_s) { /* switch 2; irregular */
        case 0:
            entity = AllocEntity(&g_Entities[64], &g_Entities[256]);
            if (entity == NULL) {
                entity = self - 3;
                entity->ext.olroxTrueFormHead.unkA9 = true;
                self->ext.olroxTrueFormHead.unkA9 = false;
                self->step_s++;
            }
            CreateEntityFromEntity(E_ID(LASER_ATTACK), self, entity);
            entity->ext.olroxTrueFormHead.parent = self;

            entity->params = self->ext.olroxTrueFormHead.unkA8 % 2;
            entity->facingLeft = self->facingLeft;
            entity = self - 3;
            entity->ext.olroxTrueFormHead.unkA9 = true;
            self->animCurFrame = 3;
            self->step_s++;
            break;
        case 1:
            if (!self->ext.olroxTrueFormHead.unkA9) {
                entity = self - 3;
                entity->ext.olroxTrueFormHead.unkA9 = false;
            }
            break;
        }
        break;
    case 4:
        switch (self->step_s) {
        case 0:
            self->animCurFrame = 4;
            entity = &PLAYER;
            offsetX = self->posX.i.hi - entity->posX.i.hi;
            offsetY = self->posY.i.hi - entity->posY.i.hi;
            if (self->facingLeft) {
                offsetX = -offsetX;
            }

            angle = -ratan2(-offsetY, offsetX);
            angle += 0x100;

            if (angle > 0x380) {
                angle = 0x380;
            }
            if (angle < -0x180) {
                angle = 0x180;
            }
            self->ext.olroxTrueFormHead.unk80 = angle;
            self->step_s++;
            // fallthrough

        case 1:
            var_s6 = 0;
            angle = self->ext.olroxTrueFormHead.unk80;
            var_s6 += func_801CDC80(&self->rotate, angle, 0x20);

            angle = -(angle + 0x180) / 2;
            entity = self - 3;
            var_s6 += func_us_801B163C(
                &entity->ext.olroxTrueFormHead.angle, angle, 0x20);

            if (var_s6 == 2) {
                entity->ext.olroxTrueFormHead.unkAC = true;
                self->step_s = 0;
                self->step = 9;
            }
            break;
        }
        break;
    case 9:
        switch (self->step_s) { /* switch 4; irregular */
        case 0:
            self->animCurFrame = 4;
            var_s2 = &D_us_801811EC[(self->ext.olroxTrueFormHead.unkAD) * 4];
            self->ext.olroxTrueFormHead.timer = var_s2[0];
            self->ext.olroxTrueFormHead.unk88 = var_s2[3];
            self->ext.olroxTrueFormHead.unk84 = 0;
            self->step_s++;
            // fallthrough
        case 1:
            var_s2 = &D_us_801811EC[(self->ext.olroxTrueFormHead.unkAD) * 4];
            if (!--self->ext.olroxTrueFormHead.unk88) {
                self->ext.olroxTrueFormHead.unk88 = var_s2[3];
                entity = AllocEntity(&g_Entities[160], &g_Entities[192]);
                if (entity != NULL) {
                    CreateEntityFromEntity(E_ID(FIREBALL_ATTACK), self, entity);
                    entity->ext.olroxTrueFormHead.parent = self;
                    entity->ext.olroxTrueFormHead.unkAD =
                        self->ext.olroxTrueFormHead.unkAD;
                    entity->facingLeft = self->facingLeft;
                }
            }
            if (self->ext.olroxTrueFormHead.unk84) {
                self->rotate += var_s2[2];
            } else {
                self->rotate -= var_s2[2];
            }
            if (self->rotate <
                (self->ext.olroxTrueFormHead.unk80 - var_s2[1])) {
                self->ext.olroxTrueFormHead.unk84 = 1;
            }
            if (self->rotate >
                (self->ext.olroxTrueFormHead.unk80 + var_s2[1])) {
                self->ext.olroxTrueFormHead.unk84 = 0;
            }
            if (self->rotate < ROT(-33.75)) {
                self->ext.olroxTrueFormHead.unk84 = 1;
            }
            if (self->rotate > ROT(78.75)) {
                self->ext.olroxTrueFormHead.unk84 = 0;
            }

            angle = -(self->rotate + 0x180) / 2;
            entity = self - 3;
            entity->ext.olroxTrueFormHead.angle = angle;
            if (!--self->ext.olroxTrueFormHead.timer) {
                entity = self - 3;
                self->step_s = 0;
                self->step = 1;
                entity->ext.olroxTrueFormHead.unkAC = 0;
            }
            break;
        }
        break;
    case 10:
        self->animCurFrame = 1;
        break;
    case 8:
        switch (self->step_s) { /* switch 5; irregular */
        case 0:
            primIndex = g_api.AllocPrimitives(PRIM_GT4, 1);
            if (primIndex == -1) {
                self->step_s++;
            } else {
                self->flags |= FLAG_HAS_PRIMS;
                self->primIndex = primIndex;
                prim = &g_PrimBuf[primIndex];
                self->ext.olroxTrueFormHead.prim = prim;
                func_us_801B13A8(prim);
                offsetX = self->posX.i.hi;
                offsetY = self->posY.i.hi;
                g_api.func_800EB758(offsetX, offsetY, self, self->drawFlags,
                                    (POLY_GT4*)prim, self->facingLeft);
                prim->tpage = 0x14;
                prim->clut += 0x20B;
                prim->priority = self->zPriority;
                prim->drawMode = DRAW_UNK02;
                self->step_s++;
            }
            break;
        case 1:
            self->palette = 0x219;
            self->unk5A = 0x54;
            entity = self - 3;
            if (entity->ext.olroxTrueFormHead.unk9B) {
                prim = self->ext.olroxTrueFormHead.prim;
                prim->drawMode = DRAW_HIDE;
                self->step_s++;
            }
            break;
        case 2:
            self->palette = PAL_FLAG(0x219);
            self->unk5A = 0x54;
            entity = self - 3;
            if (entity->ext.olroxTrueFormHead.unk9B == 3) {
                self->animCurFrame = 3;
                prim = self->ext.olroxTrueFormHead.prim;
                func_us_801B13A8(prim);
                offsetX = self->posX.i.hi;
                offsetY = self->posY.i.hi;
                g_api.func_800EB758(offsetX, offsetY, self, self->drawFlags,
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
    self->hitboxOffX = -FLT_TO_I(12 * rcos(self->rotate));
    self->hitboxOffY = -FLT_TO_I(12 * rsin(self->rotate));
    if (!D_us_801CE5B0) {
        if (self->step < 8 && !(Random() & 0x3F)) {
            entity = AllocEntity(&g_Entities[224], &g_Entities[256]);
            if (entity != NULL) {
                CreateEntityFromEntity(E_ID(OLROX_DROOL), self, entity);
                entity->ext.olroxTrueFormHead.parent = self;
                entity->params = (Random() & 7) + 0x10;
            }
        }
    }
}

static u8 func_us_801B5D6C(s16* arg0, s16* arg1, s16 arg2) {
    s32 i;
    u8 result;

    result = true;

    for (i = 0; i < 8; i++, arg0++, arg1++) {
        if (abs(*arg0 - *arg1) < arg2) {
            *arg0 = *arg1;
        } else {
            result = false;
            if (*arg0 > *arg1) {
                *arg0 -= arg2;
            }

            if (*arg0 < *arg1) {
                *arg0 += arg2;
            }
        }
        arg0++;
    }
    return result;
}

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

static void func_us_801B5E8C(void) {
    Primitive* prim;
    s32 i;
    s16 posX;
    s16 x0;
    s16 x1;
    s16 x2;
    s16 x3;
    s16 posY;
    s16 y0;
    s16 y1;
    s16 y2;
    s16 y3;
    s16 temp_s0_5;
    s16 var_s4_2;
    s16* var_s4;
    s16 angle;

    s16 var_s1;
    s16 var_3e;

    // x3 = saved_reg_s6;
    // y3 = saved_reg_s7;
    posX = g_CurrentEntity->posX.i.hi;
    posY = g_CurrentEntity->posY.i.hi;
    var_s4 = &g_CurrentEntity->ext.olroxTrueForm.unk88[0];
    prim = g_CurrentEntity->ext.olroxTrueForm.prim;
    angle = -0x180;

    for (i = 0; i < 9; i++, var_s4++) {
        x0 = x1;
        y0 = y1;
        x2 = x3;
        y2 = y3;

        angle = ((angle + *var_s4) / 2) + 0x400;

        var_s4_2 = 8;
        var_s1 = 8;
        var_3e = angle - *var_s4;
        var_s4_2 += FLT_TO_I(rcos(var_3e) * 6);
        var_s1 -= FLT_TO_I(rcos(var_3e) * 6);

        if (i == 0) {
            var_s1 = 0xC;
            angle = 0x260;
        }

        var_s4_2 =
            FLT_TO_I(var_s4_2 *
                     ((g_CurrentEntity->ext.olroxTrueForm.unk84 / 2) + 0x800));
        var_s1 = FLT_TO_I(
            var_s1 * ((g_CurrentEntity->ext.olroxTrueForm.unk84 / 2) + 0x800));
        x1 = x3 = posX;
        y1 = y3 = posY;

        if (g_CurrentEntity->facingLeft) {
            angle = 0x800 - angle;
        }
        x1 += FLT_TO_I(var_s4_2 * rcos(angle));
        y1 -= FLT_TO_I(var_s4_2 * rsin(angle));
        x3 -= FLT_TO_I(var_s1 * rcos(angle));
        y3 += FLT_TO_I(var_s1 * rsin(angle));
        temp_s0_5 = 11;
        temp_s0_5 =
            FLT_TO_I(temp_s0_5 * g_CurrentEntity->ext.olroxTrueForm.unk84);

        if (!g_CurrentEntity->facingLeft) {
            posX += FLT_TO_I(temp_s0_5 * rcos(*var_s4));
        } else {
            posX -= FLT_TO_I(temp_s0_5 * rcos(*var_s4));
        }
        posY -= FLT_TO_I(temp_s0_5 * rsin(*var_s4));
        angle = *var_s4;
        var_s4++;
        if (i != 0) {
            prim->tpage = 0x14;
            prim->clut = 0x20B;
            prim->x0 = x0;
            prim->x2 = x2;
            prim->y0 = y0;
            prim->y2 = y2;
            prim->x1 = x1;
            prim->x3 = x3;
            prim->y1 = y1;
            prim->y3 = y3;
            prim = prim->next;
        }
    }
}

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
            self->ext.olroxTrueForm.prim = prim;
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
            self->ext.olroxTrueForm.unk84 = 0;
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
        prim = self->ext.olroxTrueForm.prim;
        while (prim != NULL) {
            prim->clut = self->palette & 0xFFF;
            prim = prim->next;
        }
    }
    parent = self - 4;
    if (parent->ext.olroxArm.unk9B) {
        prim = self->ext.olroxTrueForm.prim;
        while (prim != NULL) {
            prim->tpage = 0x15;
            prim->clut = 0x219;
            prim = prim->next;
        }
    }
}

typedef struct {
    s16 target;
    s16 maxVelocity;
} TargetMaxVelocity;

static s32 func_us_801B6520(
    TargetMaxVelocity arg0_unk0, TargetMaxVelocity arg0_unk4,
    TargetMaxVelocity arg0_unk8, TargetMaxVelocity arg0_unkC) {
    s16* posVel;
    s32 count;
    TargetMaxVelocity _unused;

    count = 0;

    posVel = g_CurrentEntity->ext.olroxArm.unk88;
    count += func_us_801B163C(posVel, arg0_unk8.target, arg0_unk8.maxVelocity);
    posVel += 2;
    count += func_us_801B163C(posVel, arg0_unkC.target, arg0_unkC.maxVelocity);
    posVel = g_CurrentEntity->ext.olroxArm.unk80;
    count += func_us_801B163C(posVel, arg0_unk0.target, arg0_unk0.maxVelocity);
    posVel += 2;
    count += func_us_801B163C(posVel, arg0_unk4.target, arg0_unk4.maxVelocity);
    if (count == 4) {
        return true;
    }
    return false;
}

static Primitive* func_us_801B65C0(
    Point16 arg0, f32* arg1, Primitive* prim, u8 priority) {
    Entity* entity;
    s16 angle;
    s16 posX;
    s16 posY;
    s16 x_f;
    s16 x_e;
    s16 x_d;
    s16 x_c;
    s16 x_b;
    s16 x_a;
    s16 y_f;
    s16 y_e;
    s16 y_d;
    s16 y_c;
    s16 y_b;
    s16 y_a;
    u16 clut;

    s16 var_v1;

    u8* animCurFrame;

    if (priority) {
        clut = 0x20B;
        animCurFrame = &g_CurrentEntity->ext.olroxTrueFormHand.animFrames[3];
    } else {
        clut = 0x218;
        animCurFrame = &g_CurrentEntity->ext.olroxTrueFormHand.animFrames[2];
    }
    priority *= 6;
    posX = arg0.x;
    posY = arg0.y;

    angle = arg1->i.lo;
    if (g_CurrentEntity->facingLeft) {
        angle = 0x800 - angle;
    }

    x_a = posX;
    x_d = posX;
    y_a = posY;
    y_d = posY;

    x_d += FLT_TO_I(-(rcos(angle) * 8));
    x_a += FLT_TO_I(rcos(angle) * 8);
    y_d += FLT_TO_I(rsin(angle) * 8);
    y_a += FLT_TO_I(-(rsin(angle) * 8));

    var_v1 = ((animCurFrame[0] + 0x100) * 32) / 256;

    if (!g_CurrentEntity->facingLeft) {
        posX += FLT_TO_I(var_v1 * rcos(arg1->i.lo - 0x400));
    } else {
        posX -= FLT_TO_I(var_v1 * rcos(arg1->i.lo - 0x400));
    }

    posY += FLT_TO_I(-var_v1 * rsin(arg1->i.lo - 0x400));

    x_c = posX;
    x_e = posX;
    y_c = posY;
    y_e = posY;

    angle = arg1->i.lo;
    arg1++;
    if (g_CurrentEntity->facingLeft) {
        angle = 0x800 - angle;
    }

    x_e += FLT_TO_I(-(rcos(angle) * 6));
    y_e += FLT_TO_I(rsin(angle) * 6);
    x_c += FLT_TO_I(rcos(angle) * 6);
    y_c += FLT_TO_I(-(rsin(angle) * 6));

    prim->tpage = 0x14;
    prim->clut = clut;
    prim->u0 = 0xC8;
    prim->u1 = 0xC8;
    prim->u2 = 0xD4;
    prim->u3 = 0xDA;
    prim->v0 = 0x1E;
    prim->v1 = 4;
    prim->v2 = 0x20;
    prim->v3 = 4;
    prim->x0 = x_e;
    prim->x1 = x_d;
    prim->x2 = x_c;
    prim->x3 = x_a;
    prim->y0 = y_e;
    prim->y1 = y_d;
    prim->y2 = y_c;
    prim->y3 = y_a;
    prim->priority = D_us_801CE56C - 3 + priority;
    prim->drawMode = DRAW_UNK02;
    prim = prim->next;

    if (!g_CurrentEntity->facingLeft) {
        posX += FLT_TO_I(rcos(arg1->i.lo + 0x400) * 6);
    } else {
        posX -= FLT_TO_I(rcos(arg1->i.lo + 0x400) * 6);
    }
    posY += FLT_TO_I(-(rsin(arg1->i.lo + 0x400) * 6));

    x_c = posX;
    x_e = posX;
    y_c = posY;
    y_e = posY;

    angle = arg1->i.lo;
    if (g_CurrentEntity->facingLeft) {
        angle = 0x800 - angle;
    }

    x_e += FLT_TO_I(-(rcos(angle) * 6));
    y_e += FLT_TO_I(rsin(angle) * 6);
    x_c += FLT_TO_I(rcos(angle) * 6);
    y_c += FLT_TO_I(-(rsin(angle) * 6));

    var_v1 = ((animCurFrame[0] + 0x100) * 24) / 256;
    if (!g_CurrentEntity->facingLeft) {
        posX += FLT_TO_I(var_v1 * rcos(arg1->i.lo - 0x400));
    } else {
        posX -= FLT_TO_I(var_v1 * rcos(arg1->i.lo - 0x400));
    }
    posY += FLT_TO_I(-var_v1 * rsin(arg1->i.lo - 0x400));

    angle = arg1->i.lo;
    if (g_CurrentEntity->facingLeft) {
        angle = 0x800 - angle;
    }

    x_b = posX;
    x_f = posX;
    y_b = posY;
    y_f = posY;

    x_f += FLT_TO_I(-(rcos(angle) * 6));
    y_f += FLT_TO_I(rsin(angle) * 6);
    x_b += FLT_TO_I(rcos(angle) * 6);
    y_b += FLT_TO_I(-(rsin(angle) * 6));

    if (priority) {
        entity = g_CurrentEntity + 2;
        animCurFrame = &g_CurrentEntity->ext.olroxTrueFormHand.animFrames[1];
    } else {
        entity = g_CurrentEntity + 1;
        animCurFrame = &g_CurrentEntity->ext.olroxTrueFormHand.animFrames[0];
    }
    entity->posX.i.hi = posX;
    entity->posY.i.hi = posY;
    entity->animCurFrame = *animCurFrame;
    angle = arg1->i.lo;
    if (g_CurrentEntity->ext.olroxTrueFormHand.unk94) {
        entity->rotate = -(angle + 0x300);
    } else {
        entity->rotate = 0;
    }

    prim->tpage = 0x14;
    prim->clut = clut;
    prim->u0 = 0x88;
    prim->u1 = 0x9C;
    prim->u2 = 0x8C;
    prim->u3 = 0xA2;
    prim->v0 = 0x74;
    prim->v1 = 0x6D;
    prim->v2 = 0x80;
    prim->v3 = 0x77;
    prim->x0 = x_f;
    prim->x1 = x_e;
    prim->x2 = x_b;
    prim->x3 = x_c;
    prim->y0 = y_f;
    prim->y1 = y_e;
    prim->y2 = y_b;
    prim->y3 = y_c;
    prim->priority = D_us_801CE56C - 3 + priority;
    prim->drawMode = DRAW_UNK02;

    prim = prim->next;
    return prim;
}

// Entity update - Arms
extern EInit D_us_80180708;

void func_us_801B6CA4(Entity* self) {
    Entity* entity;
    Primitive* prim;
    s32 primIndex;

    s32 temp_a0;
    f32* positions;
    TargetMaxVelocity c;
    TargetMaxVelocity d;
    TargetMaxVelocity a;
    TargetMaxVelocity b;
    Point16 p;

    entity = self - 7;
    self->facingLeft = entity->facingLeft;
    self->palette = entity->palette;
    if (!entity->ext.olroxArm.unk9B) {
        self->ext.olroxArm.unk9A = 0;
        // other arm
        entity = self + 1;
        if (entity->flags & FLAG_DEAD) {
            self->ext.olroxArm.unk9A |= 2;
        }
        entity = self + 2;
        if (entity->flags & FLAG_DEAD) {
            self->ext.olroxArm.unk9A |= 1;
        }
        if ((self->ext.olroxArm.unk9A) && (self->step != 0xA)) {
            self->step = 9;
        }
    }
    if (self->flags & FLAG_DEAD) {
        self->hitboxState = 0;
    }

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_80180708);
        self->hitboxWidth = 0xC;
        self->hitboxHeight = 8;
        self->hitboxOffX = 0;
        self->hitboxOffY = 8;
        self->animCurFrame = 0;
        primIndex = g_api.AllocPrimitives(PRIM_GT4, 6);
        if (primIndex == -1) {
            self->step = 0;
        } else {
            self->flags |= FLAG_HAS_PRIMS;
            self->primIndex = primIndex;
            prim = &g_PrimBuf[primIndex];
            self->ext.olroxArm.prim = prim;
            while (prim != NULL) {
                prim->drawMode = DRAW_HIDE;
                prim = prim->next;
            }
            self->ext.olroxArm.unk88[0] = 0x180;
            self->ext.olroxArm.unk88[2] = -0x180;
            self->ext.olroxArm.unk80[0] = 0x100;
            self->ext.olroxArm.unk80[2] = -0x80;
            self->ext.olroxArm.unk91 = 0x1D;
            self->ext.olroxArm.unk90 = 0x21;
            self->ext.olroxArm.unk94 = 0;
        case 1:
            self->step_s = 0;
            entity = self + 2;
            entity->attack = g_api.enemyDefs[55].attack;
        }
        break;
    case 2:
        self->ext.olroxArm.unk94 = 0;
        switch (self->step_s) { /* switch 2; irregular */
        case 0:
            self->ext.olroxArm.unk91 = 0x1D;
            self->ext.olroxArm.unk90 = 0x21;

            c.target = -0x40;
            c.maxVelocity = 0x10;
            d.target = -0x200;
            d.maxVelocity = 0x10;
            a.target = 0x100;
            a.maxVelocity = 0x10;
            b.target = -0x300;
            b.maxVelocity = 0x10;
            temp_a0 = func_us_801B6520(a, b, c, d);
            if (temp_a0) {
                self->step_s = 1;
            }
            break;
        case 1:
            c.target = 0x80;
            c.maxVelocity = 0x10;
            d.target = -0x300;
            d.maxVelocity = 0x10;
            a.target = 0;
            a.maxVelocity = 0x10;
            b.target = -0x280;
            b.maxVelocity = 0x10;
            temp_a0 = func_us_801B6520(a, b, c, d);
            if (temp_a0) {
                self->step_s = 0;
            }
            break;
        }
        break;

    case 3:
        self->ext.olroxArm.unk94 = 0;
        self->ext.olroxArm.unk91 = 0x1F;
        self->ext.olroxArm.unk90 = 0x20;
        c.target = 0x100;
        c.maxVelocity = 0x10;
        d.target = -0x300;
        d.maxVelocity = 0x10;
        a.target = 0x100;
        a.maxVelocity = 0x10;
        b.target = -0x280;
        b.maxVelocity = 0x10;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 4:
        self->ext.olroxArm.unk94 = 0;
        self->ext.olroxArm.unk91 = 0x1F;
        self->ext.olroxArm.unk90 = 0x20;
        c.target = -0x240;
        c.maxVelocity = 0x60;
        d.target = -0x240;
        d.maxVelocity = 0x60;
        a.target = 0x200;
        a.maxVelocity = 0x60;
        b.target = -0x300;
        b.maxVelocity = 0x60;
        temp_a0 = func_us_801B6520(a, b, c, d);
        entity = self - 7;
        if (self->ext.olroxArm.unk88[0] < 0x80) {
            entity->ext.olroxTrueFormHand.unk89 = 0;
        }
        if (self->ext.olroxArm.unk88[0] < -0x80) {
            entity->ext.olroxTrueFormHand.unk89 = 3;
        }
        entity = self + 2;
        entity->attack = g_api.enemyDefs[57].attack;
        if (temp_a0) {
            if (self->ext.olroxArm.unk93 < 0x60) {
                self->ext.olroxArm.unk93 += 16;
            } else {
                entity = self + 2;
                entity->attack = g_api.enemyDefs[55].attack;
                self->step = 5;
                PlaySfxPositional(SFX_MEDUSA_WEAPON_SWING);
            }
        }
        break;
    case 5:
        self->ext.olroxArm.unk94 = 0;
        if (self->ext.olroxArm.unk93 > 0) {
            self->ext.olroxArm.unk93 -= 12;
        } else {
            self->ext.olroxArm.unk93 = 0;
            self->step = 1;
        }
        break;
    case 11:
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk91 = 0x1F;
        self->ext.olroxArm.unk90 = 0x20;
        c.target = 0x280;
        c.maxVelocity = 0x18;
        d.target = -0x200;
        d.maxVelocity = 0x18;
        a.target = -0x200;
        a.maxVelocity = 0x20;
        b.target = -0x400;
        b.maxVelocity = 0x20;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 12:
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk91 = 0x1D;
        self->ext.olroxArm.unk90 = 0x21;
        if (self->ext.olroxArm.unk93 < 0x40) {
            self->ext.olroxArm.unk93 += 8;
        }
        c.target = -0x500;
        c.maxVelocity = 0x60;
        d.target = -0x780;
        d.maxVelocity = 0x78;
        a.target = 0x180;
        a.maxVelocity = 0x40;
        b.target = -0x200;
        b.maxVelocity = 0x40;
        temp_a0 = func_us_801B6520(a, b, c, d);
        entity = self + 2;
        entity->attack = g_api.enemyDefs[58].attack;
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 13:
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk93 -= 12;
        if (self->ext.olroxArm.unk93 < 0) {
            self->ext.olroxArm.unk93 = 0;
        }
        self->ext.olroxArm.unk91 = 0x1F;
        self->ext.olroxArm.unk90 = 0x21;
        c.target = 0x100;
        c.maxVelocity = 0x40;
        d.target = -0x200;
        d.maxVelocity = 0x50;
        a.target = 0;
        a.maxVelocity = 0x40;
        b.target = -0x80;
        b.maxVelocity = 0x40;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 14:
        temp_a0 = 0;
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk91 = 0x1F;
        self->ext.olroxArm.unk90 = 0x20;
        self->ext.olroxArm.unk93 -= 12;
        if (self->ext.olroxArm.unk93 < 0) {
            self->ext.olroxArm.unk93 = 0;
        }
        c.target = -0x80;
        c.maxVelocity = 0x20;
        d.target = -0x200;
        d.maxVelocity = 0x20;
        a.target = 0x100;
        a.maxVelocity = 0x20;
        b.target = -0x300;
        b.maxVelocity = 0x20;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 6:
        self->ext.olroxArm.unk94 = 0;
        self->ext.olroxArm.unk91 = 0x1F;
        self->ext.olroxArm.unk90 = 0x20;
        c.target = 0x80;
        c.maxVelocity = 0x20;
        d.target = -0x280;
        d.maxVelocity = 0x20;
        a.target = 0;
        a.maxVelocity = 0x20;
        b.target = -0x380;
        b.maxVelocity = 0x20;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 7:
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk91 = 0x1D;
        self->ext.olroxArm.unk90 = 0x20;
        c.target = 0x100;
        c.maxVelocity = 0x10;
        d.target = -0x100;
        d.maxVelocity = 0x10;
        a.target = 0;
        a.maxVelocity = 0x10;
        b.target = -0x200;
        b.maxVelocity = 0x10;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 8:
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk91 = 0x1F;
        self->ext.olroxArm.unk90 = 0x21;
        c.target = 0x180;
        c.maxVelocity = 0x20;
        d.target = -0x100;
        d.maxVelocity = 0x20;
        a.target = 0;
        a.maxVelocity = 0x20;
        b.target = -0x140;
        b.maxVelocity = 0x20;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 9:
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk90 = 0x20;
        if (self->ext.olroxArm.unk9A == 2) {
            a.target = 0;
            a.maxVelocity = 0x18;
            b.target = -0x100;
            b.maxVelocity = 0x18;
        } else {
            a.target = 0x200;
            a.maxVelocity = 0x10;
            b.target = -0x100;
            b.maxVelocity = 0x10;
        }

        self->ext.olroxArm.unk91 = 0x1D;
        if (self->ext.olroxArm.unk9A == 1) {
            c.target = 0;
            c.maxVelocity = 0x18;
            d.target = -0x100;
            d.maxVelocity = 0x18;
        } else {
            c.target = 0x200;
            c.maxVelocity = 0x10;
            d.target = -0x100;
            d.maxVelocity = 0x10;
        }

        func_us_801B6520(a, b, c, d);

        if (!self->ext.olroxArm.unk9A) {
            self->step = 1;
        }
        break;
    case 15:
        self->ext.olroxArm.unk94 = 1;
        self->ext.olroxArm.unk91 = 0x1D;
        self->ext.olroxArm.unk90 = 0x20;
        c.target = 0x80;
        c.maxVelocity = 0x20;
        d.target = -0x100;
        d.maxVelocity = 0x20;
        a.target = 0;
        a.maxVelocity = 0x20;
        b.target = -0x200;
        b.maxVelocity = 0x20;
        temp_a0 = func_us_801B6520(a, b, c, d);
        if (temp_a0) {
            self->step = 1;
        }
        break;
    case 10:
        switch (self->step_s) {
        case 0:
            entity = self - 7;
            if (entity->ext.olroxArm.unk9B == 2) {
                self->step_s++;
            }
            break;
        case 1:
            self->ext.olroxArm.unk94 = 1;
            self->ext.olroxArm.unk91 = 0x1D;
            self->ext.olroxArm.unk90 = 0x21;
            c.target = -0x200;
            c.maxVelocity = 0x10;
            d.target = -0x300;
            d.maxVelocity = 0x10;
            a.target = -0x100;
            a.maxVelocity = 0x10;
            b.target = -0x400;
            b.maxVelocity = 0x10;
            temp_a0 = func_us_801B6520(a, b, c, d);
            if (temp_a0) {
                self->step_s++;
            }
            entity = self - 7;
            if (entity->ext.olroxArm.unk9B == 3) {
                self->step_s = 3;
            }
            break;
        case 2:
            self->ext.olroxArm.unk94 = 1;
            self->ext.olroxArm.unk91 = 0x1D;
            self->ext.olroxArm.unk90 = 0x21;
            c.target = 0;
            c.maxVelocity = 6;
            d.target = -0x100;
            d.maxVelocity = 6;
            a.target = 0x100;
            a.maxVelocity = 0xA;
            b.target = -0x200;
            b.maxVelocity = 0xA;
            temp_a0 = func_us_801B6520(a, b, c, d);

            entity = self - 7;
            if (entity->ext.olroxArm.unk9B == 3) {
                self->step_s = 3;
            }
            break;
        case 3:
            break;
        }
        break;
    }

    prim = self->ext.olroxArm.prim;
    positions = self->ext.olroxArm.unk88;
    p.x = self->posX.i.hi;
    p.y = self->posY.i.hi;

    prim = func_us_801B65C0(p, positions, prim, 1);

    positions = self->ext.olroxArm.unk80;
    p.x = self->posX.i.hi;
    p.y = self->posY.i.hi;
    prim = func_us_801B65C0(p, positions, prim, 0);
    if (self->palette & PAL_UNK_FLAG) {
        prim = self->ext.olroxArm.prim;
        while (prim != NULL) {
            prim->clut = self->palette & 0xFFF;
            prim = prim->next;
        }
    }

    entity = self - 7;
    if (entity->ext.olroxArm.unk9B) {
        prim = self->ext.olroxArm.prim;
        while (prim != NULL) {
            prim->tpage = 0x15;
            prim->clut = 0x219;
            prim = prim->next;
        }
    }
}

extern EInit D_us_80180708;

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

    case 1:
        if (self->flags & FLAG_DEAD) {
            self->hitboxState = 0;
            self->step = 2;
            self->step_s = 0;
        }
        break;
    case 2:
        switch (self->step_s) { /* switch 2; irregular */
        case 0:
            MakeExplosions();
            self->animCurFrame = 0;
            0;
            self->drawFlags |= ENTITY_SCALEY | ENTITY_SCALEX;
            self->flags &= -0x100;
            self->scaleX = self->scaleY = 0;
            self->step_s++;
            self->ext.olroxTrueForm.unk94 = 0x100;
            break;
        case 1:
            if (!--self->ext.olroxTrueForm.unk94) {
                self->step_s++;
            }
            break;
        case 2:
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
    case 3:
        self->drawFlags = ENTITY_ROTATE;
        switch (self->step_s) { /* switch 3; irregular */
        case 0:
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
        case 1:
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
        case 2:
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

extern EInit D_us_80180708;

// Entity update
void func_us_801B7BAC(Entity* self) {
    OlroxTrueForm* unkOlrox;

    if (self->flags & FLAG_DEAD) {
        self->hitboxState = 0;
    }
    if (!self->step) {
        InitializeEntity(D_us_80180708);
        self->animCurFrame = 0;
        self->hitboxOffY = 4;
        self->hitboxWidth = 4;
        self->hitboxHeight = 0x10;
    }
    unkOlrox = self->ext.olroxDeath.trueForm8C;
    self->posX.i.hi = unkOlrox->offsetX.i.hi;
    self->posY.i.hi = unkOlrox->offsetY.i.hi;
}

// looks for primitives lists with `target` primitives with DRAW_HIDE set.
static Primitive* func_us_801B7C44(Primitive* start, u8 target) {
    Primitive* prim;
    s32 count;

    prim = start;

    while (prim != NULL) {
        if (prim->drawMode & DRAW_HIDE) {
            start = prim;
            count = 1;
            while (count < target) {
                prim = prim->next;
                if (prim == NULL) {
                    return NULL;
                } else if (prim->drawMode & DRAW_HIDE) {
                    count++;
                } else {
                    break;
                }
            }

            if (count == target) {
                return start;
            }
        }

        prim = prim->next;
    }

    return NULL;
}

// Entity update - death animation
extern EInit D_us_80180708;
extern s16 D_us_801812D8[];
extern s32 currentMusicId;
extern s32 stopMusicFlag;

void func_us_801B7CC8(Entity* self) {
    s32 primIndex;
    s32 count;
    s32 i;
    Entity* entity;
    Primitive* next;
    Primitive* prim2;
    Primitive* prim;

    switch (self->step) {
    case 0:
        InitializeEntity(D_us_80180708);
        self->zPriority = D_us_801CE56C + 8;
        self->animCurFrame = 0;
        self->flags |= FLAG_POS_CAMERA_LOCKED;
        primIndex = g_api.func_800EDB58(4, 0x108);
        if (primIndex == -1) {
            DestroyEntity(self);
            return;
        }
        self->flags |= FLAG_HAS_PRIMS;
        self->primIndex = primIndex;
        prim = &g_PrimBuf[primIndex];
        self->ext.olroxTrueForm.prim = prim;
        entity = self - 10;
        for (i = 0; i < 10; i++, entity++) {
            prim2 = entity->ext.olroxTrueForm.prim;
            while (prim2 != NULL) {
                next = prim->next;
                *prim = *prim2;
                prim->next = next;
                prim->clut = 0x20B;
                prim->priority += 8;
                prim->r0 = prim->r1 = prim->r2 = prim->r3 = 0x80;
                prim2 = prim2->next;
                prim = prim->next;
            }
        }
        self->ext.olroxDeath.prim = prim;
        while (prim != NULL) {
            prim->drawMode = DRAW_HIDE;
            prim = prim->next;
        }
        break;
    case 1:
        // drop all the skin from olrox
        count = 0;
        prim2 = self->ext.olroxTrueForm.prim;
        while (prim2 != self->ext.olroxDeath.prim) {
            if (!(prim2->drawMode & DRAW_HIDE)) {
                count++;
                if (!(Random() & 0xF)) {
                    prim = self->ext.olroxDeath.prim;
                    prim = func_us_801B7C44(prim, 4);
                    if (prim != NULL) {
                        prim2->r0 = 0xB0;
                        prim2->r1 = 0x98;
                        prim2->r2 = 0xA0;
                        prim2->r3 = 0x88;
                        UnkRecursivePrimFunc2(prim2, 1, prim, SPAD(0));
                        prim2->drawMode = DRAW_HIDE;
                    }
                }
            }
            prim2 = prim2->next;
        }
        prim2 = self->ext.olroxDeath.prim;
        while (prim2 != NULL) {
            if (!(prim2->drawMode & DRAW_HIDE)) {
                count++;
                if (prim2->r0 > 0x80) {
                    prim2->r0--;
                    if (prim2->r0 == 0x80) {
                        prim = self->ext.olroxDeath.prim;
                        prim = func_us_801B7C44(prim, 4);
                        if (prim != NULL) {
                            prim2->r0 = 0x20;
                            prim2->r1 = 0x14;
                            prim2->r2 = 0x18;
                            prim2->r3 = 0x10;
                            UnkRecursivePrimFunc2(prim2, 1, prim, SPAD(0));
                            prim2->drawMode = DRAW_HIDE;
                            prim2->p3 = 0;
                        } else {
                            prim2->r0 += (Random() & 0x1F) + 2;
                        }
                    }
                } else {
                    if (!--prim2->r0) {
                        prim2->p3 = 0;
                        prim2->drawMode = DRAW_HIDE;
                    } else {
                        if (prim2->r0 < 16) {
                            prim2->y0 += 8 - (prim2->r0 / 2);
                            prim2->y1 += 8 - (prim2->r0 / 2);
                            prim2->y2 += 8 - (prim2->r0 / 2);
                            prim2->y3 += 8 - (prim2->r0 / 2);
                        }
                    }
                }
            }
            prim2 = prim2->next;
        }
        if (count == 0) {
            entity = self - 10;
            entity->ext.olroxDeath.unk9B = 2;
            self->step++;
        }
        break;
    case 2:
        // skin has fallen off, moving into crouched position
        entity = self - 10;
        if (entity->ext.olroxDeath.unk9B == 3) {
            prim = self->ext.olroxTrueForm.prim;
            self->ext.olroxDeath.prim80 = prim;
            prim->type = PRIM_G4;
            prim->x0 = prim->x1 = prim->x2 = prim->x3 = self->posX.i.hi;
            prim->y0 = prim->y1 = 0;
            prim->y2 = prim->y3 = 0xF0;
            prim->r0 = prim->g0 = prim->b0 = 0;
            LOW(prim->r1) = LOW(prim->r0);
            prim->r2 = 0xF0;
            prim->g2 = 0xF0;
            prim->b2 = 0xF0;
            LOW(prim->r3) = LOW(prim->r2);
            prim->priority = D_us_801CE56C + 0x10;
            prim->drawMode = DRAW_UNK_40 | DRAW_TPAGE2 | DRAW_TPAGE |
                             DRAW_COLORS | DRAW_UNK02 | DRAW_TRANSP;
            prim = prim->next;

            self->ext.olroxTrueForm.prim = prim;
            // n.b.! odd entity increment that is immediately overwritten
            for (i = 0; i < 6; i++, entity++) {
                entity = self - 10;
                entity += D_us_801812D8[i];
                prim2 = entity->ext.olroxTrueForm.prim;
                while (prim2 != NULL) {
                    next = prim->next;
                    *prim = *prim2;
                    prim->next = next;
                    prim->clut = 0x219;
                    prim2 = prim2->next;
                    prim = prim->next;
                }
            }
            self->ext.olroxDeath.prim = prim;
            while (prim != NULL) {
                prim->drawMode = DRAW_HIDE;
                prim = prim->next;
            }
            self->ext.olroxTrueForm.unk84 = 0x28;
            self->step++;
        }
        break;
    case 3:
        // reached crouching position, light bar swipes across the screen
        prim = self->ext.olroxDeath.prim80;
        prim->x2 = prim->x0 -= 6;
        prim->x3 = prim->x1 += 6;
        prim->y0 = prim->y1 = 0;
        prim->y2 = prim->y3 = 0xF0;

        if ((prim->x0 & 0xF000) && (prim->x3 & 0xF00)) {
            prim->x0 = prim->x2 = 0;
            prim->x1 = prim->x3 = 0x100;
            prim->drawMode &= ~DRAW_UNK02;
            self->ext.olroxDeath.timer = 1;
            self->step++;
            entity = AllocEntity(&g_Entities[224], &g_Entities[256]);
            if (entity != NULL) {
                CreateEntityFromEntity(E_ID(UNK_3E), self, entity);
                entity->facingLeft = self->facingLeft;
                self->ext.olroxDeath.next = entity;
            }
        }
        break;
    case 4:
        // light beams moving up skeleton being pulled up
        if (!--self->ext.olroxDeath.timer) {
            g_api.PlaySfx(SFX_METAL_CLANG_A);
            self->ext.olroxDeath.timer = 4;
            prim2 = self->ext.olroxTrueForm.prim;
            for (i = 0; i < self->ext.olroxTrueForm.unk84; i++) {
                prim2 = prim2->next;
            }
            prim = self->ext.olroxDeath.prim;
            prim = FindFirstUnkPrim2(prim, 4);
            if (prim != NULL) {
                prim2->p3 = 1;
                prim2->r0 = 0x24;
                prim2->r1 = 0x28;
                prim2->r2 = 0x2C;
                prim2->r3 = 0x21;
                UnkRecursivePrimFunc2(prim2, 1, prim, SPAD(0));
                prim2->drawMode |= DRAW_HIDE;
                self->ext.olroxTrueForm.unk84--;
                if (self->ext.olroxTrueForm.unk84 < 0) {
                    g_api.PlaySfx(SFX_TELEPORT_BANG_B);
                    self->step++;
                }
            }
        }
        // fallthrough
    case 5:
        // more light beams moving up skeleton being pulled up
        prim = self->ext.olroxDeath.prim80;
        if (g_Timer % 2) {
            prim->drawMode =
                DRAW_UNK_40 | DRAW_TPAGE2 | DRAW_TPAGE | DRAW_TRANSP;
        } else {
            prim->drawMode = DRAW_HIDE;
        }
        count = self->ext.olroxTrueForm.unk84;
        prim2 = self->ext.olroxDeath.prim;
        self->ext.olroxTrueForm.unk88[0]++;
        while (prim2 != NULL) {
            if (!(prim2->drawMode & DRAW_HIDE)) {
                count++;
                prim2->r0--;
                switch ((prim2->r0 & 0xF0) >> 4) { /* switch 2; irregular */
                case 3:
                case 2:
                    if (self->ext.olroxTrueForm.unk88[0] & 1) {
                        prim2->x0 += 1;
                        prim2->x1 += 1;
                        prim2->x2 += 1;
                        prim2->x3 += 1;
                    } else {
                        prim2->x0 -= 1;
                        prim2->x1 -= 1;
                        prim2->x2 -= 1;
                        prim2->x3 -= 1;
                    }
                    break;
                case 1:
                    if (prim2->r0 == 16) {
                        prim = self->ext.olroxDeath.prim;
                        prim = FindFirstUnkPrim2(prim, 4);
                        if (prim != NULL) {
                            prim2->p3 = 3;
                            prim2->r0 = 0xD;
                            prim2->r1 = 6;
                            prim2->r2 = 0xE;
                            prim2->r3 = 0x14;
                            UnkRecursivePrimFunc2(prim2, 1, prim, SPAD(0));
                            prim2->drawMode = DRAW_HIDE;
                            prim2->p3 = 0;
                        } else {
                            prim2->r0 += Random() & 0xF;
                        }
                    }
                    prim2->y0 -= 1;
                    prim2->y1 -= 1;
                    prim2->y2 -= 1;
                    prim2->y3 -= 1;
                    break;
                case 0:
                    prim2->y0 -= 8 - (prim2->r0 / 2);
                    prim2->y1 -= 8 - (prim2->r0 / 2);
                    prim2->y2 -= 8 - (prim2->r0 / 2);
                    prim2->y3 -= 8 - (prim2->r0 / 2);
                    if (!prim2->r0) {
                        prim2->drawMode = DRAW_HIDE;
                        prim2->p3 = 0;
                    }
                }
            }
            prim2 = prim2->next;
        }
        if (count < 0) {
            entity = self - 10;
            entity->ext.olroxDeath.unk9B = 2;
            entity = self->ext.olroxDeath.next;
            entity->step++;
            self->step++;
        }
        break;
    case 6:
        // end of the light beam, shrinking horizontally
        prim = self->ext.olroxDeath.prim80;
        prim->drawMode = DRAW_UNK_40 | DRAW_TPAGE2 | DRAW_TPAGE | DRAW_TRANSP;
        prim->y0 = prim->y1 = 0;
        prim->y2 = prim->y3 = 0xF0;
        prim->x2 = prim->x0 += 2;
        prim->x3 = prim->x1 -= 2;

        if (prim->x0 > prim->x1) {
            prim->drawMode = DRAW_HIDE;
            self->ext.olroxDeath.timer = 1;
            self->step++;
        }
        break;
    case 7:
        // create the life up
        entity = AllocEntity(&g_Entities[160], &g_Entities[192]);
        if (entity != NULL) {
            CreateEntityFromEntity(E_ID(LIFE_UP_SPAWN), self, entity);
            entity->posY.i.hi -= 0x28;
            entity->params = 0;
            D_us_80181190 = 1;
            stopMusicFlag = 1;
            currentMusicId = 0x317;
            self->step++;
        }
        break;
    case 8:
        // end
        if (g_api.func_80131F68() == false) {
            stopMusicFlag = 0;
            g_api.PlaySfx(currentMusicId);
            DestroyEntity(self);
        }
        break;
    }
}
