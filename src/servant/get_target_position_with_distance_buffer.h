// SPDX-License-Identifier: AGPL-3.0-or-later
s16 GetTargetPositionWithDistanceBuffer(
    s16 currentX, s16 targetX, s16 distanceBuffer) {
    s16 distanceDifference = abs(targetX - currentX);
    if (distanceBuffer > distanceDifference) {
        distanceBuffer = distanceDifference;
    }

    if (targetX < currentX) {
        if (distanceDifference < 0x800) {
            targetX += distanceBuffer;
        } else {
            targetX -= distanceBuffer;
        }
    } else {
        if (distanceDifference < 0x800) {
            targetX -= distanceBuffer;
        } else {
            targetX += distanceBuffer;
        }
    }
    return targetX & 0xFFF;
}
