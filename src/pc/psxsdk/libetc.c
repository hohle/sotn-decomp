#include <common.h>
#include <psxsdk/libetc.h>
#include <log.h>

void MyPadInit(int mode);
void PadInit(int mode) { MyPadInit(mode); }

u_long MyPadRead(int id);
u_long PadRead(int id) { return MyPadRead(id); }

int VSyncCallback(void (*f)()) { NOT_IMPLEMENTED; }

int VSyncCallbacks(int ch, void (*f)()) { NOT_IMPLEMENTED; }

long SetVideoMode(long mode) { NOT_IMPLEMENTED; }