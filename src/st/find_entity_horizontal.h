// SPDX-License-Identifier: AGPL-3.0-or-later
/*
 * Scans `g_LayoutObjVertical` looking for the next element with
 * an x  position to the right of the provided argument or the end
 * of the list.
 *
 * - Parameters:
 *   - posX - the position to search for
 *
 * - Side Effects:
 *    `g_LayoutObjHorizontal` will be positioned at an element with a
 *    x position larger than `posX` or the tail eleement.
 */
static void FindFirstEntityToTheRight(s16 posX) {
    while (1) {
        u16* layoutEntity = g_LayoutObjHorizontal;
        if (layoutEntity[LAYOUT_OBJ_POS_X] != LAYOUT_OBJ_START &&
            layoutEntity[LAYOUT_OBJ_POS_X] >= posX) {
            break;
        }

        g_LayoutObjHorizontal += sizeof(LayoutEntity) / sizeof(u16);
    }
}

/*
 * Scans `g_LayoutObjHorizontal` looking for the next element with an x
 * position below the provided argument or the beginning of the list.
 *
 * - Parameters:
 *   - posX - the position to search for
 *
 * - Side Effects:
 *    `g_LayoutObjVertical` will be positioned at an element with an
 *    x position smaller than `posX` or the head element.
 */
static void FindFirstEntityToTheLeft(s16 posX) {
    while (true) {
        u16* layoutEntity = g_LayoutObjHorizontal;
        if (layoutEntity[LAYOUT_OBJ_POS_X] != LAYOUT_OBJ_END &&
            (layoutEntity[LAYOUT_OBJ_POS_X] <= posX ||
             layoutEntity[LAYOUT_OBJ_POS_X] == LAYOUT_OBJ_START)) {
            break;
        }
        g_LayoutObjHorizontal -= sizeof(LayoutEntity) / sizeof(u16);
    }
}
