#include "common.h"
#include "dra.h"

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E2398);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E2438);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E249C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E2824);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E2B00);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E2E98);

void nullsub_8(void) {
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E2F3C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E31C0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E3278);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E346C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E34A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E34DC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E3574);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E3618);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E36C8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E376C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E385C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E38CC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", entrypoint_sotn);

void func_800E4124(s32 context) {
    D_8003C734 = context;
    D_80073060 = 0;
    D_8006C39C = 0;
    D_8006C3A0 = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E414C);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E44EC)
#else
void func_800E44EC(void) {
   ClearImage(&c_backbufferClear, 0, 0, 0);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E451C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E493C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E4970);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E4A04);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E4A14);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E5358);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E5498);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E5584);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E5D30);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E6218);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E6250);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E6300);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E6358);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E6FD4);

void nullsub_9(void) {
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E738C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E7458);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E768C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E7AEC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E7BB8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E7D08);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E7D4C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E7E08);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E81FC);

void func_800E8D24(void) {
    s8* phi_v1;
    s32 phi_v0;
    s8 a0;

    D_80097496 = 0;
    phi_v1 = &D_80137460;
    a0 = 0x10;
    phi_v0 = 0xF;
    do {
        *phi_v1 = a0;
        phi_v1 += 1;
        phi_v0--;
    } while (phi_v0 >= 0);
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E8D54);
// https://decomp.me/scratch/YhofM

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E8DF0);
#else
void func_800E8DF0(void) {
    Unkstruct1* phi_v1;
    Unkstruct1* phi_a0;
    s32 phi_a1;

    func_80015238(0);
    phi_a0 = &D_80097490;
    phi_a1 = 0;
    phi_v1 = &D_80097490.unk2;
    
    do {
        phi_a1++;
        phi_v1->unk2 = 0;
        phi_v1->unk0 = 0;
        phi_v1 += 1;
        phi_a0->unk0 = 0;
        phi_a0++;
    } while (phi_a1 < 2);
    func_800E8D24();
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E8E48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E8EE4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E908C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E912C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E91B0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9208);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E928C);

void func_800E92E4(void) {
    D_8013B660 = 0;
}

void func_800E92F4(void) {
    D_8013B158 = 0;
    D_8013B3D0 = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E930C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9508);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9530);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9610);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9640);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E96E8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E97BC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9804);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9880);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9B18);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9BA4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9BDC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800E9C14);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EA2B0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EA48C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EA538);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EA5AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EA5E4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EA720);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EA7CC);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EAD0C);
#else
void func_800EAD0C(void) {
    func_800EA5E4(4);
    func_800EA5E4(5);
    func_800EA5E4(6);
    func_800EA5E4(7);
    func_800EA5E4(8);
    if (g_CurrentPlayableCharacter == 0 && D_800974A0 != 0x1F) {
        func_800EA5E4(0x17);
    }
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EAD7C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EAEA4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EAEEC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EAF28);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EAFC8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB03C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB098);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB314);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB4F8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB534);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB6B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB720);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EB758);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EBB70);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EBBAC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800ECBF8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800ECE2C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800ECE58);

INCLUDE_ASM("asm/dra/nonmatchings/42398", SetRoomForegroundLayer);

INCLUDE_ASM("asm/dra/nonmatchings/42398", SetRoomBackgroundLayer);

INCLUDE_ASM("asm/dra/nonmatchings/42398", LoadRoomLayer);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDA70);
#else
void func_800EDA70(s32 *context) {
    s32 i;
    s32 n = 0xd;
    for (i = 0; i < n; i++) {
        *context++ = 0;
    }
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDA94);

void func_800EDAE4(void) {
    s32 i;
    s32 *phi_v1 = &D_800974AC;
    for (i = 0xF; i >= 0; i--)
    {
        *phi_v1 = 0;
        phi_v1 += 0x10;
    }
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDB08);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDB58);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDC80);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDD9C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDE78);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EDEDC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", CheckCollision);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800EFBF8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F0334);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F04A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F0578);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F0608);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F087C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F0940);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F0BC0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F0CD8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1424);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F14CC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F16D0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1770);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F17C8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F180C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1868);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F18C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1954);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1A3C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1B08);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1D54);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1EB0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F1FC4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F2014);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F2120);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F223C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F2288);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F2404);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F24F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F2658);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F27F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F2860);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F298C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F483C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", IsAlucart);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F4994);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F4D38);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F4F48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F4FD0);

void func_800F53A4(void) {
    func_800F4994();
    func_800F4F48();
    func_800F4FD0();
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F53D4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F548C);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", IsSpriteOutsideDrawArea);
#else
s32 IsSpriteOutsideDrawArea(s32 x0, s32 x1, s32 y0, s32 y1, MenuContext* a5) {
    s16 scissorX = (s16)a5->unk1.x;
    if (scissorX < x1) {
        s16 scissorY = (s16)a5->unk1.y;
        if (scissorY < y1 && x0 < (scissorX + (s16)a5->unk1.w))
            return (y0 < scissorY + (s16)a5->unk1.h) ^ 1;
    }
    
    return true;
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5530);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F564C);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", ScissorSprite);
#else
bool ScissorSprite(SPRT* sprite, MenuContext* arg1) {
    s16 spriteX = sprite->x0;
    s16 spriteY = sprite->y0;
    if (IsSpriteOutsideDrawArea(spriteX, spriteX + sprite->w, spriteY, spriteY + sprite->h, arg1) == false) {
        s16 scissorx0;
        s16 scissory0;
        s32 scissory1;
        s32 scissorx1;
        s32 spritex1;
        s32 spritey1;

        scissorx0 = arg1->unk1.x;
        if (sprite->x0 < scissorx0) {
            s32 a0 = sprite->x0;
            s32 diffx = scissorx0 - a0;
            sprite->x0 = a0 + diffx;
            sprite->u0 = sprite->u0 + diffx;
            sprite->w = sprite->w - diffx;
        }

        scissory0 = arg1->unk1.y;
        if (sprite->y0 < scissory0) {
            s32 diffy = scissory0 - sprite->y0;
            sprite->y0 = sprite->y0 + diffy;
            sprite->v0 = sprite->v0 + diffy;
            sprite->h = sprite->h - diffy;
        }

        scissorx1 = (s16)arg1->unk1.x + (s16)arg1->unk1.w;
        spritex1 = sprite->x0 + sprite->w;
        if (scissorx1 < spritex1) {
            sprite->w = sprite->w - (spritex1 - scissorx1);
        }

        scissory1 = (s16)arg1->unk1.y + (s16)arg1->unk1.h;
        spritey1 = sprite->y0 + sprite->h;
        if (scissory1 < spritey1) {
            sprite->h = sprite->h - (spritey1 - scissory1);
        }

        return false;
    }
    return true;
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5904);
// https://decomp.me/scratch/DP2LU

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5A90);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5AE4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5B90);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5D44);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5E68);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F5EF0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F622C);

s32 func_800F62E8(s32 context) {
    s32 temp_v0 = context * 3;
    s32 phi_v0 = temp_v0 < 0 ? temp_v0 + 3 : temp_v0;
    return phi_v0 >> 2;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6304);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F643C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6508);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6568);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6618);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F66BC);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", DrawMenuChar);
#else
void DrawMenuChar(s32 ch, int x, int y, void* context) {
    func_800F5904(context, x, y, 8, 8, (ch & 0xF) * 8, (u32) (ch & 0xF0) >> 1, 0x196, 0x1E, 1, 0);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", DrawMenuStr);
// https://decomp.me/scratch/S4Dzb

INCLUDE_ASM("asm/dra/nonmatchings/42398", DrawMenuInt);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6998);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6A48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6A70);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6BEC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6CC0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F6DC8);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", DrawSettingsButton);
#else
extern s32 g_menuButtonSettingsCursorPos;
extern s32 g_menuButtonSettingsConfig[];
extern u8 c_chPlaystationButtons[];
extern u8 c_chShoulderButtons[];
void DrawSettingsButton(MenuContext* context) {
    const int ActionCount = 7;
    const char** strAction;
    s32 tmpi;
    s32 curX;
    s32 curY;
    s32 buttonId;
    s32 i;

    i = 0;
    strAction = &c_strButtonRightHand;
    curY = 48;
    for (; i < ActionCount; i++)
    {
        DrawMenuStr(*strAction, 0x98, curY, context);
        buttonId = g_menuButtonSettingsConfig[i];
        curX = buttonId * 0xC;
        DrawMenuChar(c_chPlaystationButtons[buttonId], curX + 0x30 + 0xC0, curY, context);
        strAction++;
        if (buttonId >= 4) {
            DrawMenuChar(c_chShoulderButtons[buttonId], curX + 0x38 + 0xC0, curY, context);
        }

        curY += 16;
    }

    func_800F5E68(context, g_menuButtonSettingsCursorPos, 0x96, 0x2E, 0x54, 0xC, 4, 1);
}
#endif

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", DrawSettingsReverseCloak);
#else
void DrawSettingsReverseCloak(MenuContext* context) {
    DrawMenuStr(c_strNormal, 176, 48, context);
    DrawMenuStr(c_strReversal, 176, 64, context);
    func_800F5E68(context, g_SettingsCloakMode, 174, 46, 64, 12, 4, 1);
}
#endif

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", DrawSettingsSound);
#else
void DrawSettingsSound(MenuContext* context) {
    s16 cursorX = context->cursorX;
    s16 cursorY = context->cursorY;
    s32 subMenuX = cursorX + 4;
    DrawMenuStr(c_strStereo, subMenuX, cursorY + 4, context);
    DrawMenuStr(c_strMono, subMenuX, cursorY + 0x14, context);
    func_800F5E68(context, g_SettingsSoundMode, cursorX + 2, cursorY + 2, 53, 12, 4, 1);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F7218);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F7244);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F72BC);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", DrawPauseMenu);
#else
void func_800F622C(MenuContext* context);
void func_800F66BC(s32, s32 x, s32 y, MenuContext*, s32);
void func_800F6998(s32, s32 x, s32 y, MenuContext*, s32);
extern s32 D_8003C760;
extern s32 D_8003C9B0;
extern s32 D_8003C9FC;
extern s32 D_80097C1C;
extern s32 D_800A2D68;
extern s32 D_800A2D6C;
extern const char* D_800A83AC[];
extern s32 c_arrExpNext[];
extern s16 D_8013761C;
extern s32/*?*/ D_8013763A;
extern const u8 c_chPlaystationButtons[];
extern const u8 c_chShoulderButtons[];
extern s32 g_menuButtonSettingsConfig;
extern s32 player_stat_str;

void DrawPauseMenu(s32 arg0) {
    MenuContext* context;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s4;
    s32 temp_v0;
    s32 playerLevel;
    s32 temp_v1_2;
    const char* strPlayerName;
    s32 expNext;
    s32 phi_s4;
    s32 phi_s3;
    s32 phi_s5;
    char phi_a0_3;
    s32 phi_a1;
    s32 phi_a0_4;
    s32 phi_a1_2;
    s32 phi_a2;
    s32 phi_s4_2;
    s32 phi_s3_2;
    s32 phi_s0;
    s32* phi_s5_2;
    s32* phi_s1;
    s32 phi_a0_5;
    s32 phi_a1_3;
    s32 phi_s5_3;

    context = &D_8013761C + (arg0 * 15);
    func_800F53A4();
    if (arg0 == 1) {
        func_800F622C(context);

        if (IsAlucart() != 0) {
            strPlayerName = c_strALUCART;
        } else {
            strPlayerName = c_strALUCARD;
        }
        DrawMenuStr(strPlayerName, 0x80, 0x28, context);
        DrawMenuStr(c_strHP, 0x60, 0x38, context);
        DrawMenuInt(g_playerHp, 0xA8, 0x38, context);
        DrawMenuChar(0xF, 0xB0, 0x38, context);
        DrawMenuInt(g_playerHpMax, 0xD0, 0x38, context);
        DrawMenuStr(c_strMP, 0x60, 0x44, context);
        DrawMenuInt(g_playerMp, 0xA8, 0x44, context);
        DrawMenuChar(0xF, 0xB0, 0x44, context);
        DrawMenuInt(g_playerMpMax, 0xD0, 0x44, context);
        DrawMenuStr(c_strHEART, 0x60, 0x50, context);
        DrawMenuInt(g_playerHeart, 0xA8, 0x50, context);
        DrawMenuChar(0xF, 0xB0, 0x50, context);
        DrawMenuInt(g_playerHeartMax, 0xD0, 0x50, context);
        DrawMenuStr(c_strEXP, 0x20, 0xB0, context);
        DrawMenuInt(g_playerExp, 0x90, 0xB0, context);
        DrawMenuStr(c_strNEXT, 0x20, 0xBC, context);
        playerLevel = g_playerLevel;
        if (playerLevel != 99) {
            expNext = c_arrExpNext[playerLevel] - g_playerExp;
        } else {
            expNext = 0;
        }
        DrawMenuInt(expNext, 0x90, 0xBC, context);
        DrawMenuStr(c_strGOLD, 0x20, 0xC8, context);
        DrawMenuInt(g_playerGold, 0x90, 0xC8, context);
        DrawMenuStr(c_strLEVEL, 0xF8, 0x28, context);
        DrawMenuInt(g_playerLevel, 0x130, 0x28, context);
        DrawMenuStr(c_strSTATUS, 0xF8, 0x38, context);

        temp_v1_2 = D_80072F2C;
        phi_s4 = 0x25;
        if ((temp_v1_2 & 0x8000) != 0) {
            phi_s4 = 0x28;
        }
        if ((temp_v1_2 & 0x4000) != 0) {
            phi_s4 = 0x26;
        }
        if ((temp_v1_2 & 0x80) != 0) {
            phi_s4 = 0x27;
        }
        if (func_800F4944() != 0) {
            phi_s4 = 0x2D;
        }
        DrawMenuStr((&c_strGOLD)[phi_s4], 0x104, 0x44, context); // TODO probably wrong
        DrawMenuStr(c_strROOMS, 0xF0, 0x96, context);
        DrawMenuInt(D_8003C760, 0x148, 0x96, context);
        DrawMenuStr(c_strKILLS, 0xF0, 0xA4, context);
        DrawMenuInt(g_killCount, 0x148, 0xA4, context);
        DrawMenuStr(c_strTIME, 0xD0, 0xC0, context);
        DrawMenuInt(g_timeHours, 0x108, 0xC0, context);
        DrawMenuChar(0x1A, 0x110, 0xC0, context);
        func_800F6998(g_timeMinutes, 0x120, 0xC0, context, 2);
        DrawMenuChar(0x1A, 0x128, 0xC0, context);
        func_800F6998(g_timeSeconds, 0x138, 0xC0, context, 2);
    }

    phi_s3 = 0xE8;
    if (context == &D_8013763A) {
        phi_s3 = 0xF8;
        phi_s5 = 0x58;
    } else {
        phi_s5 = 0x50;
    }
    func_800F66BC(D_800A2D68, phi_s3, phi_s5, context, 1);

    temp_s1 = g_menuButtonSettingsConfig;
    phi_a1 = phi_s3 + 0x2C;
    if (temp_s1 < 4) {
        phi_a0_3 = (s32) c_chPlaystationButtons[temp_s1];
    } else {
        DrawMenuChar((s32) c_chPlaystationButtons[temp_s1], phi_s3 + 0x28, phi_s5, context);
        phi_a0_3 = (s32) c_chShoulderButtons[temp_s1];
        phi_a1 = phi_s3 + 0x30;
    }
    DrawMenuChar(phi_a0_3, phi_a1, phi_s5, context);
    DrawMenuInt(D_80097C1C, phi_s3 + 0x4C, phi_s5, context);

    temp_s1_2 = D_8003C9FC;
    phi_a1_2 = phi_s3 + 0x2C;
    if (temp_s1_2 < 4) {
        phi_a0_4 = (s32)c_chPlaystationButtons[temp_s1_2];
        phi_a2 = phi_s5 + 0xA;
    } else {
        temp_s0 = phi_s5 + 0xA;
        DrawMenuChar((s32)c_chPlaystationButtons[temp_s1_2], phi_s3 + 0x28, temp_s0, context);
        phi_a0_4 = (s32)c_chShoulderButtons[temp_s1_2];
        phi_a1_2 = phi_s3 + 0x30;
        phi_a2 = temp_s0;
    }
    DrawMenuChar(phi_a0_4, phi_a1_2, phi_a2, context);
    temp_s0_2 = phi_s3 + 0x4C;
    DrawMenuInt(D_80097C20, temp_s0_2, phi_s5 + 0xA, context);
    func_800F66BC(D_800A2D6C, phi_s3, phi_s5 + 0x14, context, 1);
    DrawMenuInt(D_80097C24, temp_s0_2, phi_s5 + 0x1A, context);

    if (context == &D_8013763A) {
        phi_s3_2 = 0x20;
        phi_s5_3 = 0x78;
    } else {
        DrawMenuStr(D_800A83AC[D_8003C9B0], 8, 0x28, context);
        phi_s3_2 = 0xC;
        phi_s5_3 = 0x46;
    }
    phi_s4_2 = 0;
    phi_s0 = phi_s5_3;
    phi_s5_2 = &player_stat_str;
    phi_s1 = &player_stat_str + 0x10;
    do {
        DrawMenuStr(*(&c_strSTR + (phi_s4_2 * 4)), phi_s3_2, phi_s0, context);
        DrawMenuInt(*phi_s5_2, phi_s3_2 + 0x2C, phi_s0, context);
        temp_v0 = *phi_s1;
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                DrawMenuChar(0xB, phi_s3_2 + 0x34, phi_s0, context);
                phi_a0_5 = *phi_s1;
                phi_a1_3 = phi_s3_2 + 0x44;
            } else {
                DrawMenuChar(0xD, phi_s3_2 + 0x34, phi_s0, context);
                phi_a0_5 = -(s32) *phi_s1;
                phi_a1_3 = phi_s3_2 + 0x44;
            }
            DrawMenuInt(phi_a0_5, phi_a1_3, phi_s0, context);
        }
        temp_s4 = phi_s4_2 + 1;
        phi_s4_2 = temp_s4;
        phi_s0 += 0xC;
        phi_s5_2 += 4;
        phi_s1 += 4;
    } while (temp_s4 < 4);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F7B60);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F7F64);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F82F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F8374);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F84CC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F86E4);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F8754);
#else
void func_800F8754(MenuContext* context, s32 x, s32 y) {
    s32 curX;
    s32 phi_a1;

    if (D_801375DC == 0) {
        D_8013784C = 1;
    }

    DrawMenuStr(c_strSpells, x + 14, y + 20, context);
    if (D_801375FC == 0) {
        D_8013784C = 1;
    } else {
        D_8013784C = 0;
    }
    
    phi_a1 = x + 2;
    DrawMenuStr(c_strFamiliars, phi_a1, y + 68, context);
    D_8013784C = 0;
    DrawMenuStr(c_strEquip, x + 18, y + 4, context);
    curX = x + 0xE;
    DrawMenuStr(c_strRelics, curX, y + 36, context);
    DrawMenuStr(c_strSystem, curX, y + 52, context);
}
#endif

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F8858);
#else
void func_800F8858(MenuContext* context) {
    s32 i = 0;
    const char** pStrEquipTypes = &c_strSSword;
    s32 curY = 8;
    s32* phi_s1 = &D_8003CACC;
    s32 nexti;

    do {
        nexti = i + 1;
        DrawMenuStr(pStrEquipTypes[*phi_s1], context->cursorX + 4, context->cursorY + curY, context);
        phi_s1++;
        curY += 0x10;
        i = nexti;
    } while (i < 0xB);
    
    func_800F5E68(context, D_80137618, (s16) context->cursorX + 2, (s16) context->cursorY + 4, 0x48, 0x10, 0, 1);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F892C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F8990);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F8C98);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F8E18);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F8F28);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F9690);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F96F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F97DC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F9808);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F98AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F99B8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F9D40);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F9D88);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F9DD0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F9E18);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800F9F40);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FA034);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FA3C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FA60C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FA7E8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FA8C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FA9DC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAB1C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAB8C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FABBC);

void func_800FABEC(s32 context) {
    ((s8*)&D_80137638)[context * 0x1E] = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAC0C);

void func_800FAC30(void) {
    D_80137844 = 0;
    D_80137848 = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAC48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAC98);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FACB8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAD34);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FADC0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAE98);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAEC4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FAF44);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FB004);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FB0FC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FB160);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FB1EC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FB23C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FB9BC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FBAC4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FBC24);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD39C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD4C0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD5BC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD664);
// s32 func_800FD664(s32 context) {
//     s32 phi_a0 = context;
//     if ((D_800974A0 & 0x20) != 0) {
//         phi_a0 <<= 1;
//     }
//     return phi_a0;
// }

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD688);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD6C4);

u8 *func_800FD744(s32 context) {
    u8 *phi_v0 = &D_80097A8D;
    if (context != 0) {
        phi_v0 += 0xA9;
    }
    return phi_v0;
}

u8 *func_800FD760(s32 context) {
    s8 *phi_v0 = &D_8009798A;
    if (context != 0) {
        phi_v0 += 0xA9;
    }
    return phi_v0;
}

s32 func_800FD77C(s32 context, s32 arg1) {
    if (context == 0) {
        return *(&D_800A4B04 + (arg1 * 13));
    }
    
    return *(&D_800A7718 + (arg1 << 3));
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD7C0);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD874);
#else
void func_800FD874(u16 context, s32 arg1) {
    u8 *temp_a0_2;
    u8 *temp_v0;
    u8 temp_a1;
    u8 temp_v1;
    u8 *phi_a0;
    u8 *phi_a0_2;
    u16 i;
    s32 phi_a1;
    s32 phi_a1_2;

    u8 *cursorY = func_800FD744(arg1);
    u8* temp_a3 = func_800FD760(arg1);
    u16 temp_a2 = context & 0xFFFF;
    u8 *temp_a0 = temp_a3 + temp_a2;
    if (*temp_a0 < 0x63) {
        temp_a1 = *temp_a0;
        *temp_a0 = temp_a1 + 1;
        if (*temp_a0 == 1) {
            *temp_a0 = temp_a1;
            if (arg1 != 0) {
                i = *(&D_800A7734 + (temp_a2 << 5));
            }
            
            phi_a0 = cursorY;
            phi_a1 = 0;
            phi_a1_2 = 0;
            while (true) {
                if (*++phi_a0 == temp_a2)
                    break;
                phi_a1_2 += 1;
            }

            phi_a0_2 = cursorY;
loop_8:
            temp_v1 = *phi_a0_2;
            if (*((s8*)temp_a3 + temp_v1) != 0) {
block_12:
                phi_a0_2 += 1;
                phi_a1 += 1;
                goto loop_8;
            }
            if ((arg1 != 0) && (i != *(&D_800A7734 + (temp_v1 << 5)))) {
                goto block_12;
            }

            temp_v0 = temp_a3 + (context & 0xFFFF);
            *temp_v0 += 1;
            temp_a0_2 = &cursorY[phi_a1];
            if (phi_a1 < phi_a1_2) {
                cursorY[phi_a1_2] = *temp_a0_2;
                *temp_a0_2 = context;
            }
        }
    }
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FD9D4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FDB18);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FDC94);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FDCE0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FDD44);

void func_800FDE00(void) {
    D_80137960 = 0;
    D_80137964 = 0;
    D_80137968 = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FDE20);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FE044);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FE3A8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FE3C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FE728);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FE8B4);

void func_800FE8F0(void) {
   if (D_8013B5E8 == 0) {
       D_8013B5E8 = 0x40;
   }
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FE914);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FE97C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FEE6C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FEEA4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF064);

void func_800FF0A0(s32 context) {
    *(&D_80139828 + (context * 1)) = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF0B8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF0F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF110);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF128);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF460);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF494);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF60C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF6C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF708);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_800FF7B8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80100750);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80100B50);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010183C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010189C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80101A80);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801024DC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801025F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80102628);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801026BC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801027A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801027C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801028AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80102CD8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80102D08);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80102D70);

void func_80102DEC(s32 context) {
    D_80137E64 = 0;
    D_80137E68 = context;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80102E04);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80102EB8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801030B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80103148);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80103238);

void func_80103EAC(void) {
    D_80137E4C = 0;
    func_800E92F4();
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80103ED4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010427C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801042C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80104790);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80105078);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80105408);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80105428);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80106590);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801065F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80106670);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80106A28);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010715C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801071CC);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107250);
#else
void func_80107250(s32 context, s32 arg1) {
    func_801071CC(context, arg1, 0);
    func_801071CC(context, arg1, 1);
    func_801071CC(context, arg1, 2);
    func_801071CC(context, arg1, 3);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801072BC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801072DC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801072FC);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", SetMenuBackgroundRect);
#else
void SetMenuBackgroundRect(UnkPoly* context, s16 x, s16 y, s32 width, s32 height) {
    s16 x1 = x + width;
    s16 y1 = y + height;

    context->x0 = x;
    context->y0 = y;
    context->x1 = x1;
    context->y1 = y;
    context->unk20 = x;
    context->unk2C = x1;
    context->unk22 = y1;
    context->unk2E = y1;
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107360);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801073C0);
#else
void func_801073C0(void) {
    func_800195C8(0);
    func_800199D0(0);
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801073E8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107460);

INCLUDE_ASM("asm/dra/nonmatchings/42398", CopyMapOverlayCallback);
// https://decomp.me/scratch/1AWN1

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107614);
//https://decomp.me/scratch/U0IGY

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107750);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801078C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107B04);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107C6C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107DB4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80107EF0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801080DC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010838C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801083BC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801083F0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80108448);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801092E8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80109328);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801093C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80109594);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80109990);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80109A44);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010A234);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010A3F0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010A4A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010A5BC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010BF64);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010BFFC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010C36C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010C9F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010D010);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010D2C8);

void func_8010D584(s16 context) {
    D_80073404 = context;
    D_80073406 = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010D59C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010D800);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DA2C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DA48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DA70);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DB38);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DBFC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DDA0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DF70);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010DFF0);

void func_8010E0A8(void) {
    D_80073512 = 0;
}

void func_8010E0B8(void) {
    D_80073511 = 0;
    D_80073510 = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E0D0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E168);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E1EC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E234);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E27C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E334);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E390);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E3B8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E3E0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E42C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E470);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E4D0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E570);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E6AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E7AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E83C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E940);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010E9A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010EA54);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010EADC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010EB5C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010EC8C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010ED54);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010EDB8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FAF4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FB24);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FB68);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FBF4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FC50);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FCB8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FD24);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FD88);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8010FDF8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80110394);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801104D0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801106A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011081C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80110968);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80110BC8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80110DF8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80111018);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801112AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011151C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80111830);

void func_80111928(void) {
    D_801396EA = 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80111938);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011197C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801119C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80111CC0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80111D24);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80111DE8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011203C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801120B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80112B64);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80112BB0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80113148);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801131C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801139CC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80113AAC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80113D7C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80113E68);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80113EE0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80113F7C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011405C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80114DF4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80115394);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80115BB0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80115C50);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80115DA0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80115F54);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80116208);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80116408);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801166A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011678C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801167D0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80116838);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011690C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80116994);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80116B0C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801177A0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80117AC0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80117D3C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80117DEC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801182F8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118614);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118640);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118670);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801186EC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011879C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118810);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118894);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118970);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118B18);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118C28);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118C84);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80118D0C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80119588);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80119D3C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80119E78);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80119F70);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011A290);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011A328);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011A3AC);

void func_8011A4C8(void) {
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011A4D0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011A870);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011A9D8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011AAFC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011AC3C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011B190);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011B334);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011B480);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011B530);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011B5A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011BBE0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011BD48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011BDA4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011D9F8);

void func_8011E0E4(void) {
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011E0EC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011E390);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011E4BC);

void func_8011EDA0(void) {
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011EDA8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011F074);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011F24C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8011F934);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801200AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80120AF8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80120DD0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80121980);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80121F14);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80121F58);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012231C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80123788);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801238CC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80123A60);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80123B40);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80123F78);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80124164);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801243B0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80124A8C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80124B88);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80125330);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80125A30);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80125B6C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80125C2C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80125E68);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801262AC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801267B0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80126C48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80126ECC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801274DC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012768C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80127840);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801279FC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80127CC8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80127EAC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80127EF0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80127F40);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80128714);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80128BBC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80128C2C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801291C4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80129864);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012A0A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012A528);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012A89C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012B78C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012B990);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012BEF8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012C600);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012C88C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012C97C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CA64);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CB0C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CB4C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CC30);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CCE4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CED4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CFA8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012CFF0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012D024);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012D178);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012D28C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012D3E8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012DBBC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012DF04);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012E040);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012E550);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012E7A4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012E9C0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012EAD0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012ED30);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012EF2C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012F178);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012F83C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8012F894);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80130264);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80130618);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801309B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80130E94);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8013136C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801315F8);

void func_80131EBC(s32 context, s32 arg1) {
    D_80138784[arg1 << 0x10 >> 0x10] = context;
}

void func_80131ED8(s32 value) {
    D_80138F20 = value;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80131EE8);

void func_80131F04(void) {
    D_80139020 = 0;
    D_8013B694 = D_8013B694 + 1;
}

s32 func_80131F28(void) {
    return D_80138F7C;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80131F38);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80131F68);
#else
bool func_80131F68(void) {
    if (D_8013B61C == 0) {
        return D_8013901C != 0;
    }
    return true;
}
#endif

s16 func_80131F94(void) {
    return D_8013B668;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80131FA4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80131FCC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132028);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132134);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8013216C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801321FC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132264);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801324B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132500);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801325D8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801326D8);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8013271C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132760);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801327B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132A04);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132C2C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132E38);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132E90);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80132F60);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133290);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133488);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133604);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133780);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801337B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133810);

s32 func_80133940(void) {
    return D_801396F4 == 0;
}

s32 func_80133950(void) {
    return D_8013980C == 0;
}

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133960);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133BDC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80133FCC);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134104);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8013415C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801341B4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134388);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134508);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134564);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801345C0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8013461C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134678);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134714);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801347F8);
#else
void func_801347F8(s32 arg0) {
    if (D_8013AEEC == 0)
        return;

    if (((arg0 - 0x601) & 0xFFFF) < 0x2E0U) {
        s16 playerLevel = D_80139000;
        s32 temp_v0 = playerLevel * 3;
        *(&D_801390DC + temp_v0) = arg0 - 0x600;
        D_80139000 = ++playerLevel;
        *(&D_801390DE + temp_v0) = 0xFFFF;
        *(&D_801390E0 + temp_v0) = 0;
        if (playerLevel == 0x100) {
            D_80139000 = 0;
        }
    } else {
        s16 temp_v0_2;
        s16 temp_v0_3;
        if (arg0 < 0x85) {
            if (arg0 < 0x80) {
                if (arg0 < 0x12 && arg0 >= 0x10) {
                    D_8013980C = 1;
                }
            } else {
                D_8013B61C = 1;
            }
        } else if (arg0 < 0x95 && arg0 >= 0x90) {
            D_8013B61C = 1;
        }
        
        temp_v0_2 = D_80139A70;
        temp_v0_3 = temp_v0_2 + 1;
        D_80139A70 = temp_v0_3;
        D_8013B3E8[temp_v0_2] = arg0;
        if (temp_v0_3 == 0x100) {
            D_80139A70 = 0;
        }
    }
}
#endif

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8013493C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801349F4);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134B48);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134C60);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134D14);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134E64);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80134F50);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801353A0);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80135484);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80135624);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_8013572C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80135C00);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80135C2C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80135D8C);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_80136010);

INCLUDE_ASM("asm/dra/nonmatchings/42398", func_801361F8);

void nullsub_10(void) {
}
