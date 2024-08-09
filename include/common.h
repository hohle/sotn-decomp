#ifndef COMMON_H
#define COMMON_H

#if defined(_internal_version_us)
#define VERSION_US
#define VERSION "us"
#elif defined(_internal_version_hd)
#define VERSION_HD
#define VERSION "hd"
#elif defined(_internal_version_pspeu)
#define VERSION_PSP
#define VERSION "psp"
#elif defined(_internal_version_beta)
#define VERSION_BETA
#define VERSION "beta"
#else
#warning "Version not specified. Falling back to the US version."
#define VERSION_US
#define VERSION "us"
#endif

#include "include_asm.h"
#include "settings.h"
#include "types.h"

#define LEN(x) ((s32)(sizeof(x) / sizeof(*(x))))
#define OFF(type, field) ((size_t)(&((type*)0)->field))
#define STRCPY(dst, src) __builtin_memcpy(dst, src, sizeof(src))
#define SQ(x) ((x) * (x))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (b) : (a))

#ifdef _MSC_VER
#define __builtin_memcpy memcpy
#endif

#define LOH(x) (*(s16*)&(x))
#define HIH(x) (((s16*)&(x))[1])
#define LOHU(x) (*(u16*)&(x))
#define LOW(x) (*(s32*)&(x))
#define LOWU(x) (*(u32*)&(x))

#if defined(HACKS) && !defined(PERMUTER)
#define ALIGNED4 __attribute__((aligned(4)))
#else
#define ALIGNED4
#endif

#ifndef __clang__
int sprintf(char* dst, const char* fmt, ...);
#endif

// Converts a given value to a fixed-point value, where
// 16 bits represents the integer part and 16 bits for fractional part
#define FIX(x) ((s32)((x) * 65536.0))
// Get the integer part of such a fixed-point value
#define FIX_TO_I(x) ((s32)((x) >> 16))
// Get the fractional part of such a fixed-point value
#define FIX_FRAC(x) (*(s16*)&(x))

// The second argument to CreateEntFactoryFromEntity has weird bit packing,
// this takes the 2 relevant inputs and packs them up.
// A0 should be a value like 0x##00 where ## is two hexadecimal digits.
// BLUEPRINTNUM is which blueprint gets loaded from g_FactoryBlueprints.
#define FACTORY(A0, BLUEPRINTNUM) (A0 << 8 | BLUEPRINTNUM)
// Tests multiple bits of x being set, based on the bitmask defined in y.
#define TEST_BITS(x, y) ((x & y) == y)

// PSX SDK libraries do not use float. Instead they use a fix-point number
// where 4096 is equal to 1.0.
#define FLT(x) ((s32)((x) * 4096.0))

// Access to the Scratchpad memory. Different on different systems.
#if defined(VERSION_PC)
#define SP_LEN 0x400
#define SP(x) (&sp[x])
#elif defined(VERSION_PSP)
#define SP(x) (0x00010000 + (x))
#else
#define SP(x) (0x1F800000 + (x))
#endif

#define CLAMP_MIN(v, min) ((v) < (min) ? (min) : (v))
#define CLAMP_MAX(v, max) ((v) > (max) ? (max) : (v))

// Creates padding between variables with a unique name and file
// visibility. On versions where this padding is unnecessary, these
// macros expand to nothing. "Critical" versions of these macros
// ensure that the padding is provided, regardless of version, useful
// for when locations are accessed using a variety of sizes so
// field offset needs to be maintained. The unknown critical versions
// expand identically to the critical versions but indicate that it
// is not known whether or not the padding is necessary outside of
// reproducing an original binary.
#define __INDIRECT_CRITICAL_PAD_TYPE_FIELD(type, size, line, counter) type __pad__ ## size ## __ ## line ## __ ## counter[size]
#define __CRITICAL_PAD_TYPE_FIELD(type, size, line, counter) __INDIRECT_CRITICAL_PAD_TYPE_FIELD(type, size, line, counter)
#define CRITICAL_PAD_TYPE_FIELD(type, size) __CRITICAL_PAD_TYPE_FIELD(type, size, __LINE__, __COUNTER__)
#define CRITICAL_PAD_FIELD(size) CRITICAL_PAD_TYPE_FIELD(uint8_t, size)

#define UNKNOWN_CRITICAL_PAD_TYPE(type, size) CRITICAL_PAD_TYPE_FIELD(type, size)
#define UNKNOWN_CRITICAL_PAD_FIELD(size) CRITICAL_PAD_FIELD(size)

#ifndef VERSION_PC
#define PAD_FIELD(size) const CRITICAL_PAD_FIELD(size)
#define STATIC_PAD_BSS(size) static CRITICAL_PAD_FIELD(size)
#define STATIC_PAD_DATA(size) STATIC_PAD_BSS(size) = {0}
#define STATIC_PAD_RODATA(size) static const STATIC_PAD_BSS(size) = {0}
#else
#define PAD_FIELD(size)
#define STATIC_PAD_BSS(size)
#define STATIC_PAD_DATA(size)
#define STATIC_PAD_RODATA(size)
#endif

#endif
