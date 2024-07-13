#ifndef GAME_H
#define GAME_H

#include "common.h"

#include "animset.h"
#include "castle.h"
#include "clut.h"
#include "collider.h"
#include "cutscene.h"
#include "demo.h"
#include "disk.h"
#include "drawmode.h"
#include "entity.h"
#include "gamepad.h"
#include "gamesettings.h"
#include "gapi.h"
#include "graphics.h"
#include "gstate.h"
#include "familiar.h"
#include "item.h"
#include "items.h"
#include "layer.h"
#include "log.h"
#include "memcard.h"
#include "menunavigation.h"
#include "palette.h"
#include "player.h"
#include "primitive.h"
#include "relic.h"
#include "servant.h"
#include "sotnstr.h"
#include "spell.h"
#include "sprite.h"
#include "stage.h"
#include "stageoverlay.h"
#include "timeattack.h"
#include "timer.h"
#include "ui.h"
#include <psxsdk/kernel.h>

// lseek etc. conflicts
#ifndef VERSION_PC
#include <psxsdk/libapi.h>
#include <psxsdk/libc.h>
#endif

#include <psxsdk/libcd.h>
#include <psxsdk/libetc.h>
#include <psxsdk/libgpu.h>
#include <psxsdk/libgs.h>
#include <psxsdk/libgte.h>
#include <psxsdk/libspu.h>
#include <psxsdk/libsnd.h>
#include <psxsdk/romio.h>

typedef struct {
    /* 0x00 */ SVECTOR* v0;
    /* 0x04 */ SVECTOR* v1;
    /* 0x08 */ SVECTOR* v2;
    /* 0x0C */ SVECTOR* v3;
} SVEC4; // size = 0x10

#define DISP_ALL_H 240
#define DISP_STAGE_W 256
#define DISP_STAGE_H DISP_ALL_H
#define DISP_MENU_W 384
#define DISP_MENU_H DISP_ALL_H
#define DISP_TITLE_W 512
#define DISP_TITLE_H DISP_ALL_H

#define WEAPON_0_START 0xE0
#define WEAPON_0_END (WEAPON_1_START - 1)
#define WEAPON_1_START 0xF0

#ifndef VERSION_PC
#define RIC_PRG_PTR 0x8013C000
#define SPRITESHEET_PTR 0x8013C020 // g_PlOvlSpritesheet
#define FAMILIAR_PTR 0x80170000
#define WEAPON0_PTR 0x8017A000
#define WEAPON1_PTR 0x8017D000
#define STAGE_PRG_PTR 0x80180000
#define SIM_CHR0 0x80280000
#define SIM_CHR1 0x80284000
#define SIM_PTR 0x80280000

#else
#define RIC_PRG_PTR 0x8013C000
#define SPRITESHEET_PTR 0x8013C020 // g_PlOvlSpritesheet
#define FAMILIAR_PTR 0x80170000
#define WEAPON0_PTR 0x8017A000
#define WEAPON1_PTR 0x8017D000
#define STAGE_PRG_PTR 0x80180000
#define SIM_CHR0 0x80280000
#define SIM_CHR1 0x80284000
#define SIM_PTR 0x80280000

#endif

// used with various equipment, enemy resistances, etc
#define ELEMENT_HIT 0x20
#define ELEMENT_CUT 0x40
#define ELEMENT_POISON 0x80
#define ELEMENT_CURSE 0x100
#define ELEMENT_STONE 0x200
#define ELEMENT_WATER 0x400
#define ELEMENT_DARK 0x800
#define ELEMENT_HOLY 0x1000
#define ELEMENT_ICE 0x2000
#define ELEMENT_THUNDER 0x4000
#define ELEMENT_FIRE 0x8000

#define FONT_W 8                 // small font size used for dialogues and menu
#define FONT_H 8                 // small font size used for dialogues and menu
#define FONT_GAP FONT_W          // gap between the beginning of two letters
#define FONT_SPACE 4             // gap for the space character
#define MENUCHAR(x) ((x) - 0x20) // 8x8 characters are ASCII offset by 0x20
#define DIAG_EOL 0xFF            // end of line
#define DIAG_EOS 0x00            // end of string

#include "unkstruct.h"

typedef struct {
    f32 x;
    f32 y;
} Pos;

typedef struct {
    f32 posX;
    f32 posY;
} Camera;

typedef struct {
    unsigned char width;
    unsigned char height;
    unsigned short unk2;
#ifdef _MSC_VER
    unsigned char* data;
#else
    unsigned char data[0];
#endif
} ImgSrc;

typedef struct {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
    /* 0x4 */ u16 roomId;
    /* 0x6 */ u16 unk6;
    /* 0x8 */ u16 stageId;
} RoomTeleport; // size = 0xA

typedef struct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ Stages stageId;
    /* 0x0C */ TimeAttackEvents eventId;
    /* 0x10 */ s32 unk10;
} RoomBossTeleport; /* size=0x14 */

typedef struct XaMusicConfig {
    u32 cd_addr;
    s32 unk228;
    u8 filter_file;
    u8 filter_channel_id;
    u8 volume;
    u8 unk22f;
    u8 unk230;
    u8 pad[3];
} XaMusicConfig;

typedef struct {
    void (*D_8013C000)(void);
    void (*D_8013C004)(void);
    void (*D_8013C008)(void);
    void (*D_8013C00C)(void);
} PlayerOvl;
extern PlayerOvl g_PlOvl;
extern u8** g_PlOvlAluBatSpritesheet[1];
extern u8* g_PlOvlSpritesheet[];

extern s32 D_8003925C;

extern s32 D_8003C0EC[4];
extern s32 D_8003C0F8;
extern s32 D_8003C100;
extern s16 D_8003C710;
extern s16 D_8003C712;
extern s32 D_8003C728;
extern s32 D_8003C730;
extern s32 D_8003C738;
extern s32 D_8003C73C;
extern u32 D_8003C744;
extern u32 g_RoomCount;
extern s32 D_8003C8B8;
extern Unkstruct_8003C908 D_8003C908;
extern s32 D_8003C90C[2];
extern const char aBaslus00067dra[19];
extern s32 g_LoadFile;
extern s32 D_8006BB00;
extern s32 D_8006C374;
extern s32 D_8006C378;
extern Point32 D_8006C384;
extern Point32 D_8006C38C;
extern s32 D_8006C3AC;
extern s32 g_backbufferX;
extern s32 g_backbufferY;
extern Unkstruct_8006C3C4 D_8006C3C4[32];

extern s32 g_PrevScrollX;
extern s32 g_PrevScrollY;
extern s32 D_80073080;
extern u32 g_randomNext;
extern s32 D_80096ED8[];
extern s8 D_80097B98;
extern s8 D_80097B99;
extern s32 D_80097448[]; // underwater physics. 7448 and 744C. Could be struct.
extern s32 D_80097450;
extern Pos D_80097488;
extern s32 D_800974A4; // map open
extern DR_ENV D_800974AC[16];
extern s32 D_800978B4;
extern s32 D_800978C4;
extern char D_80097902[];
extern s32 D_80097904;
extern s32 g_ScrollDeltaX;
extern s32 g_ScrollDeltaY;
extern s32 D_80097910;
extern s32 g_LoadOvlIdx; // 0x80097918
extern s32 D_8009791C;
extern s32 D_80097920;
extern s32 D_80097924;
extern s32 D_80097928;
extern u32 D_80097C40[];
extern s32 D_800987B4;
extern s32 D_800987C8;
extern s32 D_80098894;

#endif
