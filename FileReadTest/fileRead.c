#include <stdio.h> 
#include <stdlib.h> 

// Changed return type to char* because we are returning a pointer to a string, not a single character.
char* readFile(const char* fileName) { 
    FILE *file; 
    
    file = fopen(fileName, "r"); // Added missing semicolon.
    
    if (file == NULL) { 
        perror("couldn't find file"); 
        return NULL; 
    } 
    
    fseek(file, 0, SEEK_END); 
    long byteLen = ftell(file); 
    rewind(file); 
    
    // malloc returns a void*, casting it with (char *) is optional in C but acceptable.
    // We add +1 for the null terminator '\0', not the EOF character.
    char* memory = (char *)malloc(byteLen + 1); 
    
    if (memory == NULL) { 
        // malloc fails if the SYSTEM is out of memory, not necessarily if the file is empty.
        perror("Memory allocation failed"); 
        fclose(file); // Critical: must close the file if we exit early!
        return NULL; 
    } 
    
    // size_t is an unsigned integer type used specifically for sizes and counts in C.
    size_t text = fread(memory, 1, byteLen, file); 
    
    // Append the null terminator to mark the end of the string.
    memory[text] = '\0'; 
    
    fclose(file); 
    
    // We are returning the pointer to the allocated text, NOT the size in bytes.
    return memory; 
}
