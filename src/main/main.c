#include "common.h"
#include "game.h"

extern void (*g_MainGame)();

void main(void) {

    static s32 fd;
    static CdlFILE cdlFile;
    static u8 cdlMode[4];

    ResetCallback();
    InitHeap((void*)0x801F0000, 0x7800);
    CdInit();

    g_GameState = Game_Boot;

    do {
        fd = open("sim:c:\\bin\\dra.bin", 1);
    } while (fd == -1 && --g_GameState != Game_Init);

    if (g_GameState != Game_Init) {
        read(fd, (void*)DRA_PRG_PTR, 0x130000);
        close(fd);
        g_UseDisk = 0;
        fd = open("sim:c:\\bin\\dra.bio", 1);

        if (fd != -1) {
            g_UseDisk = 2;
        }

        do {
            fd = open("sim:c:\\bin\\f_map.bin", 1);
        } while (fd < 0);

        read(fd, (void*)CASTLE_MAP_PTR, 0x8000);
        close(fd);
    } else {
    main_search_loop_1:
        while (!CdSearchFile(&cdlFile, "\\DRA.BIN;1")) {
        }

        *cdlMode = CdlModeSpeed | CdlModeSpeedNormal;
        CdControl(CdlSetmode, cdlMode, NULL);

        while (CdSync(1, NULL) != 2) {
        }

        g_GameState = (cdlFile.size + 0x7ff) >> 0xB;
        CdControl(CdlSetloc, &cdlFile, NULL);
        CdRead(g_GameState, (u32*)DRA_PRG_PTR, 0x80);
        // block until read is complete
        fd = CdReadSync(0, NULL);
        if (fd < 0) {
            goto main_search_loop_1;
        }

        g_UseDisk = 1;

    main_search_loop_2:
        if (!CdSearchFile(&cdlFile, "\\F_MAP.BIN;1")) {
            goto main_search_loop_2;
        } else {
            g_GameState = (cdlFile.size + 0x7ff) >> 0xB;
        }
        CdControl(CdlSetloc, &cdlFile, NULL);
        CdRead(g_GameState, (u32*)CASTLE_MAP_PTR, 0x80);
        // block until read is complete
        fd = CdReadSync(0, NULL);

        if (fd < 0) {
            goto main_search_loop_2;
        }
    }
    g_MainGame();
}

const char a0123456789abcd[] = "0123456789ABCDEF\0\0\0\0";
