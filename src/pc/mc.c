// SPDX-License-Identifier: BSD-3-Clause

// TODO: is this necessary?
#define VERSION_US
#define VERSION "us"

#include <common.h>

uint32_t g_MemcardFd;
uint32_t g_MemcardRetryCount;
uint32_t g_MemcardStep;
s32 g_MemcardBlockRead;
s32 g_MemcardPortMask[] = {~1, ~2};

#include "../save_mgr.h"

MemcardInfo g_MemcardInfo[2];

// TODO: figure out how to include system stdio.h
#include <bits/types/FILE.h>
extern FILE* stderr;

__attribute__((noreturn))
void usage(char* arg0) {
    fprintf(stderr,
            "usage: %s <command> [options] <memcard>\n\n"
            "Commands:\n\n"
            "  show - display save info\n"
            "  set-save-room <save-room>\n"
            "\n"
            "Options:\n\n"
            "  --help, -h      this help\n"
            "  --version, -V   version information \n"
            "  --verbose, -v   verbosity, may be set multiple times\n",
            arg0);

    exit(1);
}

int main(int argc, char* argv[]) {

    const int port = 0;

    MemcardInit();
    MemcardInfoInit();
    printf("MemcardParse -> %d\n", MemcardParse(port, 0));
    char path[20];
    MakeMemcardPath(path, 0);
    printf("Made memcard path: %s\n", path);
    printf("is sotn save: %d\n", MemcardDetectSave(port, path, 0));
    printf("read file: %d\n", MemcardReadFile(port, 0, path, g_Pix[0], 1));
    MemcardClose(port);

    usage(argv[0]);
    return 0;
}

#define unimplemented() \
	fprintf(stderr, "%s:%d __unimplemented__\n", \
            __FUNCTION__, __LINE__)

long _card_info(long chan) {
    unimplemented();
    exit(1);
}
long _card_clear(long chan) {
    unimplemented();
    exit(1);
}
long _card_load(long chan) {
    unimplemented();
    exit(1);
}
long EnableEvent(long) {
    unimplemented();
    exit(1);
}

long format(char* fs) {
    unimplemented();
    exit(1);
}

long erase(char*) {
    unimplemented();
    exit(1);
}

long TestEvent(unsigned long event){
    unimplemented();
    exit(1);
}

long OpenEvent(unsigned long, long, long, long (*func)()) {
    unimplemented();
    exit(1);
}

void EnterCriticalSection(void) {
    unimplemented();
    exit(1);
}

void ExitCriticalSection(void) {
    unimplemented();
    exit(1);
}

extern struct DIRENTRY* firstfile(char* name, struct DIRENTRY* dirent) {
    printf("%s:%d returning info about %s\n",
        __FUNCTION__, __LINE__, name);
    if (!dirent) {
        return dirent;
    }
    // TODO: this should all come from the supplied file
    *dirent = (struct DIRENTRY) {
        .name = strncpy(dirent->name, name, 20),
        .attr = 0,
        .size = CARD_BLOCK_SIZE * 16, // TODO: ?
        .next = NULL,
        .head = 0,
        .system = { 's', 'o', 't', 'n' },
    };

    return dirent;
}

extern struct DIRENTRY* nextfile(struct DIRENTRY*) {
    unimplemented();
    exit(1);
}

void _log(unsigned int level, const char* file, unsigned int line,
          const char* func, const char* fmt, ...) {
    unimplemented();
    exit(1);
}
