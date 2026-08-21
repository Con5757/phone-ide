#include <stdio.h>
#include <stdlib.h>

char readFile(const char* file) {
        FILE *file;
        
        file = fopen(file, "r")
        if (file == NULL) {
            perror("couldn't find file");
            return NULL;
        }
        
        fseek(file, 0, SEEK_END);
        long byteLen = ftell(file);
        rewind(file);
        
        char* memory = (char *)malloc(byteLen + 1);
        if (memory == NULL) {
            perror("couldn't alloc into mem");
            return NULL;
        }
        
        size_t text = fread(memory, 1, byteLen, file);
        memory[text] = '\0';
        
        fclose(file);
        return memory;
}