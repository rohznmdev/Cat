#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BSIZE 10

void readFile(int argc, char * argv);
void readUserIn();

/**
 * Represents the main method which will execute the code.
 *
 */
int main(int argc, char * argv[]) {
    // checks the input and calls the read user input function.
    if (argc == 1) {
        readUserIn(argc, argv);
    } // if
    for (int i = 1; i < argc; i++) {
        // checks certain conditions
        char * filen = argv[i];
        if (strcmp(argv[i], "-") == 0) {
            readUserIn(argc, filen);
        } else {
            readFile(argc, filen);
        } // if -else
    } // for
} // main
/**
 * represents the code for reading user input
 *
 */
void readUserIn() {
    int x;
    char b[BSIZE];
    // reads the user input for writing.
    while((x = read(STDIN_FILENO, b, BSIZE)) != 0) {
        write(STDOUT_FILENO, b, x);
    } // while
} // readUserIn

/**
 * Represents the code for reading a file.
 *
 */
void readFile(int argc, char * argv) {
    int f = open(argv, O_RDONLY);
    // checks for errors.
    if (f == -1) {
        perror("ERROR OCCURRED");
        exit(3);
    } // if
    char a[BSIZE];
    int x;
    while ((x = read(f, a, BSIZE)) != 0) {
        if (x == -1) {
            perror("ERROR");
            exit(14);
        } // if
        write(STDOUT_FILENO, a, x);
    } // while
} // readFile
