// SPDX-License-Identifier: AGPL-3.0-or-later
#ifndef BO0_ENTITY_H
#define BO0_ENTITY_H

#include <types.h>
#include <common.h>
#include <primitive.h>

typedef struct Entity;

typedef struct {
    /* 0x7C */ u32 : 32;
    /* 0x80 */ s16 timer;
    /* 0x82 */ u16 : 16;
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 unk85;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 unk88;
} ET_Olrox;

typedef struct {
    /* 0x7C */ u32 : 32;
    /* 0x80 */ s16 timer;
    /* 0x82 */ u16 : 16;
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 unk85;
    /* 0x86 */ u8 : 8;
    /* 0x87 */ u8 : 8;
    /* 0x88 */ u32 : 32;
    /* 0x8C */ u32 : 32;
    /* 0x90 */ u32 : 32;
    /* 0x94 */ u32 : 32;
    /* 0x98 */ u32 : 32;
    /* 0x9C */ u32 : 32;
    /* 0xA0 */ u32 : 32;
    /* 0xA4 */ struct Entity* parent;
    /* 0xA8 */ u8 unkA8;
} ET_OlroxAfterImage;

typedef struct {
    /* 0x7C */ Primitive* prim1;
    /* 0x80 */ Primitive* prim2;
    /* 0x84 */ Primitive* prim3;
    /* 0x88 */ Primitive* prim4;
    /* 0x8C */ Primitive* prim5;
    /* 0x90 */ Primitive* prim6;
    /* 0x94 */ u32 : 32;
    /* 0x98 */ s16 hitboxOffX;
    /* 0x9A */ u16 : 16;
    /* 0x9C */ s16 timer9C;
    /* 0x9E */ s16 timer9E;
    /* 0xA0 */ s16 timer;
    /* 0xA2 */ u16 : 16;
    /* 0xA4 */ struct Entity* next;
    /* 0xA8 */ u8 : 8;
    /* 0xA9 */ u8 unkA9;
    /* 0xAA */ u8 : 8;
    /* 0xAB */ u8 : 8;
    /* 0xAC */ u8 : 8;
    /* 0xAD */ u8 scaleIndex;
} ET_OlroxLaser;

typedef struct {
    /* 0x7C */ Primitive* prim7C;
    /* 0x80 */ s16 timer;
    /* 0x82 */ u16 : 16;
    /* 0x84 */ s16 : 16;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 : 8;
    /* 0x88 */ u32 : 32;
    /* 0x8C */ s16 timer2;
    /* 0x8E */ s16 height;
    /* 0x90 */ Primitive* prim;
    /* 0x94 */ s16 unk94;
    /* 0x94 */ s16 unk96;
    /* 0x98 */ s16 unk98;
    /* 0x9A */ s16 unk9A;
    /* 0x9C */ s16 unk9C;
    /* 0x9E */ s16 unk9E;
    /* 0xA0 */ s16 unkA0;
    /* 0xA2 */ s16 : 16;
    /* 0xA4 */ struct Entity* parent;
} ET_OlroxGroundBlast;

typedef struct {
    /* 0x7C */ u32 : 32;
    /* 0x80 */ u32 : 32;
    /* 0x84 */ u32 : 32;
    /* 0x88 */ u32 : 32;
    /* 0x8C */ u32 : 32;
    /* 0x90 */ u32 : 32;
    /* 0x94 */ u32 : 32;
    /* 0x98 */ u32 : 32;
    /* 0x9C */ u32 : 32;
    /* 0xA0 */ u32 : 32;
    /* 0xA4 */ struct Entity* parent;
} ET_OlroxPortal;

typedef struct {
    /* 0x7C */ u32 : 32;
    /* 0x80 */ u32 : 32;
    /* 0x84 */ u32 : 32;
    /* 0x88 */ u32 : 32;
    /* 0x8C */ u32 : 32;
    /* 0x90 */ u32 : 32;
    /* 0x94 */ u32 : 32;
    /* 0x98 */ u32 : 32;
    /* 0x9C */ u32 : 32;
    /* 0xA0 */ u32 : 32;
    /* 0xA4 */ u32 : 32;
    /* 0xA8 */ f32 unkAA;
} ET_OlroxBlast;

typedef struct {
    /* 0x7C */ u32 : 32;
    /* 0x80 */ u32 : 32;
    /* 0x84 */ u32 : 32;
    /* 0x88 */ u32 : 32;
    /* 0x8C */ u32 : 32;
    /* 0x90 */ u32 : 32;
    /* 0x94 */ u32 : 32;
    /* 0x98 */ u32 : 32;
    /* 0x9C */ u32 : 32;
    /* 0xA0 */ u32 : 32;
    /* 0xA4 */ struct Entity* parent;
    /* 0xA8 */ u16 : 16;
    /* 0xAA */ s16 unkAA;
} ET_OlroxSkulls;

typedef struct {
    /* 0x7C */ Primitive* prim;
    /* 0x80 */ u8 unk80;
    /* 0x81 */ u8 : 8;
    /* 0x82 */ u16 : 16;
    /* 0x84 */ s16 unk84;
    /* 0x86 */ u16 : 16;
    /* 0x88 */ s16 unk88[6];
    /* 0x94 */ s16 unk94;
    /* 0x96 */ s16 : 16;
    /* 0x98 */ u8 : 8;
    /* 0x99 */ u8 : 8;
    /* 0x9A */ u8 : 8;
    /* 0x9B */ u8 unk9B;
} ET_OlroxTrueForm;

typedef struct OlroxTrueForm {
    /* 0x00 */ u32 : 32; // probably pointer
#ifdef VERSION_PSP
    u32 : 32;
#endif
    /* 0x04 */ u32 : 32;
    /* 0x08 */ u32 : 32;
    /* 0x0C */ f32 angle; // angle?
    /* 0x10 */ f32 angle2;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ struct OlroxTrueForm* next;
    /* 0x1C */ f32 posX;
    /* 0x20 */ f32 posY;
    /* 0x24 */ u8 step;
    /* 0x25 */ u8 : 8;
    /* 0x26 */ u16 hitKind;
    /* 0x28 */ f32 offsetX;
    /* 0x2C */ f32 offsetY;
} OlroxTrueForm; // size=0x30

typedef struct {
    /* 0x7C */ Primitive* prim;
    /* 0x80 */ s16 unk80;
    /* 0x82 */ u16 : 16;
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 : 8;
    /* 0x86 */ u8 : 8;
    /* 0x87 */ u8 : 8;
    /* 0x88 */ s16 unk88;
    /* 0x8A */ u16 : 16;
    /* 0x8C */ u32 : 32;
    /* 0x90 */ s16 angle;
    /* 0x92 */ u16 : 16;
    /* 0x94 */ s16 timer;
    /* 0x96 */ u16 : 16;
    /* 0x98 */ u8 : 8;
    /* 0x99 */ u8 unk99;
    /* 0x9A */ u8 : 8;
    /* 0x9B */ u8 unk9B;
    /* 0x9C */ u32 : 32;
    /* 0xA0 */ u32 : 32;
    /* 0xA4 */ struct Entity* parent;
    /* 0xA8 */ u8 unkA8;
    /* 0xA9 */ u8 unkA9;
    /* 0xAA */ u8 unkAA;
    /* 0xAB */ u8 : 8;
    /* 0xAC */ u8 unkAC;
    /* 0xAD */ u8 unkAD;
} ET_OlroxTrueFormHead;

typedef struct {
    /* 0x7C */ u32 : 32;
    /* 0x80 */ OlroxTrueForm* trueForm1;
    /* 0x84 */ OlroxTrueForm* trueForm2;
    /* 0x88 */ u8 : 8;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u16 : 16;
    /* 0x8C */ u32 : 32;
    /* 0x90 */ u8 animFrames[4];
    /* 0x94 */ u8 unk94;
} ET_OlroxTrueFormHand;

typedef struct {
    /* 0x7C */ Primitive* prim;
    /* 0x80 */ s16 unk80[2];
    /* 0x84 */ s16 unk84[2];
    /* 0x88 */ s16 unk88[2];
    /* 0x8C */ s16 unk8A[2];
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 : 8;
    /* 0x93 */ s8 unk93;
    /* 0x94 */ u8 unk94;
    /* 0x95 */ u8 : 8;
    /* 0x96 */ u8 : 8;
    /* 0x97 */ u8 : 8;
    /* 0x98 */ u8 : 8;
    /* 0x99 */ u8 : 8;
    /* 0x9A */ u8 unk9A;
    /* 0x9B */ u8 unk9B;
} ET_OlroxArm;

typedef struct {
    /* 0x7C */ u32 : 32;
    /* 0x80 */ Primitive* prim80;
    /* 0x84 */ u32 : 32;
    /* 0x88 */ u32 : 32;
    /* 0x8C */ OlroxTrueForm* trueForm8C;
    /* 0x90 */ u32 : 32;
    /* 0x94 */ s16 timer;
    /* 0x96 */ u16 : 16;
    /* 0x98 */ u8 : 8;
    /* 0x99 */ u8 : 8;
    /* 0x9A */ u8 : 8;
    /* 0x9B */ u8 unk9B;
    /* 0x9C */ Primitive* prim;
    /* 0xA0 */ u32 : 32;
    /* 0xA4 */ struct Entity* next;
} ET_OlroxDeath;

#define STAGE_EXTENSIONS                                                       \
    ET_Olrox olrox;                                                            \
    ET_OlroxAfterImage olroxAfterImage;                                        \
    ET_OlroxDrool olroxDrool;                                                  \
    ET_OlroxLaser olroxLaser;                                                  \
    ET_OlroxGroundBlast olroxGroundBlast;                                      \
    ET_OlroxPortal olroxPortal;                                                \
    ET_OlroxBlast olroxBlast;                                                  \
    ET_OlroxSkulls olroxSkulls;                                                \
    ET_OlroxTrueForm olroxTrueForm;                                            \
    ET_OlroxTrueFormHead olroxTrueFormHead;                                    \
    ET_OlroxTrueFormHand olroxTrueFormHand;                                    \
    ET_OlroxArm olroxArm;                                                      \
    ET_OlroxDeath olroxDeath;

#endif // BO0_ENTITY_H
