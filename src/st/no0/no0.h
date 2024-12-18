// SPDX-License-Identifier: AGPL-3.0-or-later
#include "stage.h"

#define STAGE_IS_NO0

#define OVL_EXPORT(x) NO0_##x

void EntityExplosionVariants(Entity* entity);
void EntityGreyPuff(Entity* entity);

typedef enum EntityIDs {
    /* 0x00 */ E_NONE,
    /* 0x01 */ E_BREAKABLE,
    /* 0x02 */ E_EXPLOSION,
    /* 0x03 */ E_PRIZE_DROP,
    /* 0x04 */ E_NUMERIC_DAMAGE,
    /* 0x05 */ E_RED_DOOR,
    /* 0x06 */ E_INTENSE_EXPLOSION,
    /* 0x07 */ E_SOUL_STEAL_ORB,
    /* 0x08 */ E_ROOM_FOREGROUND,
    /* 0x09 */ E_STAGE_NAME_POPUP,
    /* 0x0A */ E_EQUIP_ITEM_DROP,
    /* 0x0B */ E_RELIC_ORB,
    /* 0x0C */ E_HEART_DROP,
    /* 0x0D */ E_ENEMY_BLOOD,
    /* 0x0E */ E_SAVE_GAME_POPUP,
    /* 0x0F */ E_DUMMY_0F,
    /* 0x10 */ E_DUMMY_10,
    /* 0x11 */ E_ID_11 = 0x11,
    /* 0x14 */ E_ID_14 = 0x14,
    /* 0x15 */ E_GREY_PUFF,
    /* 0x1D */ E_CLOCK_ROOM_SHADOW = 0x20,
    /* 0x3B */ E_SLINGER_THROWN_BONE = 0x3B,
    /* 0x3C */ E_SLINGER_PIECES,
    /* 0x48 */ E_AXE_KNIGHT_AXE = 0x48,
    /* 0x49 */ E_WARG_EXP_OPAQUE,
    /* 0x4A */ E_OUIJA_TABLE = 0x4A,
    /* 0x4B */ E_OUIJA_TABLE_COMPONENT,
    /* 0x4D */ E_SKELETON = 0x4D,
    /* 0x4E */ E_SKELETON_THROWN_BONE,
    /* 0x4F */ E_SKELETON_PIECES,
} EntityIDs;

#define E_PUFF_OPAQUE_PALETTE_OFFSET 0x2C0

extern s16 g_SineTable[];
extern u16 g_EInitCommon[];
extern u16 g_EInitParticle[];

// Axe knight
extern u16 g_EInitAxeKnightAxe[];

// Skeleton
extern u16 g_EInitSkeleton[];
extern u16 g_EInitSkeletonPieces[];
extern u16 g_EInitSkeletonBone[];

// Ouija Table
extern u16 g_EInitOuijaTable[];
extern u16 g_EInitOuijaTableComponent[];

// Flea Man
extern u16 g_EInitFleaMan[];

// Clock room
extern u16 g_Statues[];

// Clocks?
extern u16 D_us_80180A88[];
