#include <game.h>

s32 g_CurrentStream;
u16 g_ClutIds[0x300];
STATIC_PAD_BSS(4);
FgLayer D_8003C708;
STATIC_PAD_BSS(36);
// This address is used in `main` and `g_GameState` is
// reordered by the assembler. The others "work" because they
// are not referenced directly and are just empty data.
// GameState g_GameState;
