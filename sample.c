#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
    
    // firstly we need to ensure that the string will not overflow the available size
    uint32_t baseStringLength = strlen(cmd);
    uint32_t inputStringLength = strlen(argv[1]);

    if(baseStringLength + inputStringLength + 1 > BUFSIZE) {
        fprintf(stderr, "filename is too long");
        return -1;
    }

    strcat(cmd, argv[1]);
    system(cmd);
}
