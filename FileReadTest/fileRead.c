#include <stdio.h>

char characterize(const char* source) {
    int i = 0;
    
    if (source == NULL || source[0] == '\0') {
        return '\0';
    }
    
    while (source[i] != '\0') {
        i++;
    }
    return source[i - 1];
}