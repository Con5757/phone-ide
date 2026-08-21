#include <stdio.h>
#include <stdlib.h>

char readFile(const char* file) {
        FILE *file;
        
        file = fopen(file, "r")
        if (file == NULL) {
            perror("couldn't find file");
            return NULL;
        }
        
        char* buffer = (char *)malloc(buffer, 0, file);
        if (buffer == NULL) {
            perror("couldn't alloc into buffer");
            return NULL;
        }
        
        fclose(file)
        free
}