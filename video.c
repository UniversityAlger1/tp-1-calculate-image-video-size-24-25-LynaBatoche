
#include "config/coloredBitmap.h"
#include <stdio.h>
#include <string.h>

// Helper function to calculate the size of a single colored or grayscale bitmap
float coloredBitmap(int w, int h, char* unit) {
    float sizeInBits = (float)(w * h * 24); // Color image: 24 bits per pixel

    if (strcmp(unit, "bt") == 0) {
        return sizeInBits;
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBits / 1024.0f;
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBits / (1024.0f * 1024.0f);
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBits / (1024.0f * 1024.0f * 1024.0f);
    }

    return 0; // Invalid unit
}

// Main function to calculate the size of the video
float videoSize(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate the number of frames for color and black-and-white sections
    int framesColor = fps * durationMovie;
    int framesBW = fps * durationCredits;

    // Calculate the size of a single frame for each section
    float sizeColorFrameBits = (float)(w * h * 24); // 24 bits per pixel
    float sizeBWFrameBits = (float)(w * h * 8);    // 8 bits per pixel

    // Total size in bits
    float totalSizeBits = (framesColor * sizeColorFrameBits) + (framesBW * sizeBWFrameBits);

    // Convert to the desired unit
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBits;
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeBits / 1024.0f;
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeBits / (1024.0f * 1024.0f);
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeBits / (1024.0f * 1024.0f * 1024.0f);
    }

    return 0; // Invalid unit
}

// Example usage
int main() {
    int width = 1920;
    int height = 1080;
    int durationMovie = 300; // 5 minutes
    int durationCredits = 60; // 1 minute
    int fps = 30;
    char unit[] = "mo";

    float result = videoSize(width, height, durationMovie, durationCredits, fps, unit);
    printf("The size of the video is: %.2f %s\n", result, unit);

    return 0;
}
