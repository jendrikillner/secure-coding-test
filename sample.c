#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256
    
long int getSizeOfFile(char const * file_name) 
{ 
    FILE* fp = fopen(file_name, "r"); 
  
    // ensure the file exists 
    if (fp == NULL) { 
        return -1; 
    } 
  
    // seek to the end of the file
    // so that we can query the size of the file
    fseek(fp, 0L, SEEK_END);
  
    long int res = ftell(fp); 
  
    // closing the file 
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

    char cmd[BUFSIZE];

    long int fileSize = getSizeOfFile(argv[1]);

    if(fileSize != -1) {
        fprintf(stdout, "File size: %li.\n", fileSize);
        return
    } else {
        fprintf(stderr, "Failed to open file %s\n", file_name);
    }
}
