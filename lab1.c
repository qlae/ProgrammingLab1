#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        // If the file could not be opened, print an error message and return NULL
        printf("Failed to open file.\n");
        return NULL;
    }

    // Allocate memory to hold up to 99 characters plus a null terminator (100 total)
    char* str = (char*) malloc(sizeof(char) * 100);
    if (str == NULL) {
        // If memory allocation fails, close the file, print an error message, and return NULL
        printf("Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    // Read one line from the file (up to 99 characters)
    if (fgets(str, 100, file) == NULL) {
        // If reading fails, free the allocated memory and return NULL
        free(str);
        fclose(file);
        return NULL;
    }

    // Remove the newline character at the end of the string, if it exists
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Close the file and return the string
    fclose(file);
    return str;
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    int length = strlen(str); // Get the length of the input string

    // Calculate the total size of the exploded string using the formula n(n+1)/2
    int totalSize = (length * (length + 1)) / 2;

    // Allocate memory to hold the exploded string (+1 for null terminator)
    char* exploded = (char*) malloc((totalSize + 1) * sizeof(char));
    if (exploded == NULL) {
        // If memory allocation fails, print an error message and return NULL
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Pointer to track where to copy the next part of the exploded string
    char* currentPos = exploded;

    // For each character in the string, copy the substring starting from index 0 up to i
    for (int i = 0; i < length; ++i) {
        strncpy(currentPos, str, i + 1); // Copy the first (i+1) characters
        currentPos += i + 1;             // Move the pointer forward
    }

    // Add the null terminator at the end of the exploded string
    exploded[totalSize] = '\0';

    return exploded;
}
