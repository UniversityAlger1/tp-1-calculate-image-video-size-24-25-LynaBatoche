#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Each pixel in a colored image requires 24 bits (3 channels: Red, Green, Blue)
    float sizeInBits = (float)(w * h * 24); // Total size in bits

    // Convert based on the unit parameter
    if (strcmp(unit, "bt") == 0) {
        return sizeInBits; // Return size in bits
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBits / 1024.0f; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBits / (1024.0f * 1024.0f); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBits / (1024.0f * 1024.0f * 1024.0f); // Convert to gigabits
    }

    // If unit is invalid, return 0
    return 0;
}
