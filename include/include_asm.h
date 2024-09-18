#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define ASM_RODATA __asm__(".section .rodata")

#if !defined(PERMUTER) && !defined(VERSION_PSP)

#ifndef INCLUDE_ASM

#ifndef ASM_PREFIX
#define ASM_PREFIX "asm/" VERSION
#endif

#define INCLUDE_ASM(FOLDER, NAME)                                              \
    __asm__(".pushsection .text\n"                                             \
            "\t.align\t2\n"                                                    \
            "\t.globl\t" #NAME "\n"                                            \
            "\t.ent\t" #NAME "\n" #NAME ":\n"                                  \
            ".include \"" ASM_PREFIX "/" FOLDER "/" #NAME ".s\"\n"            \
            "\t.set reorder\n"                                                 \
            "\t.set at\n"                                                      \
            "\t.end\t" #NAME "\n"                                              \
            ".popsection")

#define INCLUDE_RODATA(FOLDER, NAME)                                           \
    __asm__(".pushsection .rodata\n"                                           \
            ".include \"" ASM_PREFIX "/" FOLDER "/" #NAME ".s\"\n"            \
            ".popsection")

#endif

// omit .global
#ifdef USE_INCLUDE_ASM
__asm__(".include \"macro.inc\"\n");
#endif

#else // PERMUTER || VERSION_PSP
#define INCLUDE_ASM(FOLDER, NAME)
#endif

#endif
