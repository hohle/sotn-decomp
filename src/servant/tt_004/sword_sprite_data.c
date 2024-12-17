// SPDX-License-Identifier: AGPL-3.0-or-later
#include "sword.h"
#include <psxsdk/libgte.h>

u16 g_ServantClut[] = {
    0x0000, 0x0841, 0x0C80, 0x2D60, 0x56A0, 0x5FE0, 0x5607, 0x6ED2,
    0x7FFC, 0x00EE, 0x01F4, 0x0F5F, 0x3FFF, 0x000A, 0x0010, 0x0016,
};

VECTOR D_us_80170060 = {
    0,
    0,
    0x1964,
};

SVECTOR D_us_80170070 = {0, 0, 0};

// sprite data may end here

u16 D_us_80170078[2] = {0};
u16 D_us_8017007C[2] = {0};

// n.b.! need individual symbols until dependencies are decompiled
// VECTOR D_us_80170080 = { 0 };
s32 D_us_80170080 = 0;
s32 D_us_80170080_y = 0;
s32 D_us_80170080_z = 0;
STATIC_PAD_DATA(4);

// sound effects ID
s16 D_us_80170090[] = {
    0x8B2,
    0x8B3,
    0x8B4,
    0x8B5,
};

// more sound effect IDs
s16 D_us_80170098[] = {
    0x8B6,
    0x8B7,
    0x8B8,
    0,
};

SwordUnk_A0 D_us_801700A0[10] = {
    {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1},
    {0, 1, 0, 1}, {0, 1, 0, 1}, {1, 1, 0, 1}, {1, 1, 0, 1}, {1, 1, 0, 3},
};

SVECTOR D_us_80170118 = {
    -60,
    -85,
    0,
    0,
};
SVECTOR D_us_80170120 = {
    61,
    -85,
    0,
    0,
};
SVECTOR D_us_80170128 = {
    -60,
    274,
    0,
    0,
};
SVECTOR D_us_80170130 = {
    61,
    274,
    0,
    0,
};
SVECTOR D_us_80170138 = {
    0,
    90,
    0,
    0,
};
SVECTOR D_us_80170140 = {
    0,
    274,
    0,
    0,
};

SVECTOR D_us_80170148[] = {
    {
        -22,
        0x50,
        0,
        0,
    },
    {
        -22,
        240,
        0,
        0,
    },
    {
        0,
        90,
        0,
        0,
    },
    {
        0,
        240,
        0,
        0,
    },
    {
        22,
        0x50,
        0,
        0,
    },
    {
        22,
        240,
        0,
        0,
    },
    {
        0,
        90,
        0,
        0,
    },
    {
        0,
        240,
        0,
        0,
    },
    {
        -22,
        240,
        0,
        0,
    },
    {
        0,
        290,
        0,
        0,
    },
    {
        0,
        240,
        0,
        0,
    },
    {
        0,
        240,
        0,
        0,
    },
    {
        22,
        240,
        0,
        0,
    },
    {
        0,
        290,
        0,
        0,
    },
    {
        0,
        240,
        0,
        0,
    },
    {
        0,
        240,
        0,
        0,
    },
};
