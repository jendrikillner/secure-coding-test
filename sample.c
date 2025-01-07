#include <string.h>
#include <stdio.h>
#include <stdlib.h>
    
long get_size_of_file(char const * file_name) 
{ 
    FILE* fp = fopen(file_name, "r"); 
  
    // ensure the file exists 
    if (fp == NULL) { 
        return -1; 
    } 
  
    // seek to the end of the file
    // so that we can query the size of the file
    fseek(fp, 0L, SEEK_END);
  
    long res = ftell(fp); 
  
    // ensure to close the file 
    fclose(fp); 
  
    return res; 
} 

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {

    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    char const * file_name = argv[1];
    long fileSize = get_size_of_file(file_name);

    if(fileSize != -1) {
        // emulate the wc -c output
        // number of bytes followed by the name of the file
        fprintf(stdout, "%li %s", fileSize, file_name);
    } else {
        fprintf(stderr, "Failed to open file %s\n", file_name);
    }
}
