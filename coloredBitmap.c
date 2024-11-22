#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
   // Calculate the size in bytes 
    float size_in_bytes = (float)(w * h * 3);
    // in bits: float size_in_bits = (float)(w * h * 24);
    // Convert size based on the unit parameter
    if (strcmp(unit, "bt") == 0) {
        // Return the size in bits
        return size_in_bytes;
    } 
    else if (strcmp(unit, "ko") == 0) {
        // Convert bits to kilobits
        return size_in_bytes / 1024.0f;
    } 
    else if (strcmp(unit, "mo") == 0) {
        // Convert bits to megabits
        return size_in_bytes / (1024.0f * 1024.0f);
    } 
    else if (strcmp(unit, "go") == 0) {
        // Convert bits to gigabits
        return size_in_bytes / (1024.0f * 1024.0f * 1024.0f);
    } 
    else {
        // If unit is unrecognized, return 0 as a fallback
        return 0.0f;
    }
   // YOUR CODE HERE - END
}
