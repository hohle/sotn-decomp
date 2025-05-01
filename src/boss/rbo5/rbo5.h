// SPDX-License-Identifier: AGPL-3.0-or-later
#ifndef RBO5_H
#define RBO5_H

#include <stage.h>

#define OVL_EXPORT(x) RBO5_##x
#define STAGE_FLAG OVL_EXPORT(STAGE_FLAG)

#include "../doppleganger.h"

#ifdef VERSION_PSP
extern s32 D_pspeu_0926BCC8;
extern s32 D_pspeu_0926BCB8;
extern s32 D_pspeu_0926BCB0;
extern s32 D_pspeu_0926BCA0;
extern s32 D_pspeu_0926BC98;
#define E_ID(ID_17) D_pspeu_0926BCC8
#define E_ID(ID_19) D_pspeu_0926BCB8
#define E_ID(ID_1A) D_pspeu_0926BCB0
#define E_ID(ID_1C) D_pspeu_0926BCA0
#define E_ID(ID_1D) D_pspeu_0926BC98
#endif

#endif // RBO5_H
