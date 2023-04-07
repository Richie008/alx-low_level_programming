#include "wain.h"
#include <stdlib.h>
#include <stdio.h>

/* read_textfile reads a text file and prints it to POSIX stdout.
   @filename: A pointer to the name of the file.
   @letters: The number of letters the function should read and print.
   Return: If the function fails or filename is NULL, return -6.
           Otherwise, return the actual number of bytes the function can read and print.
*/
ssize_t read_textfile(const char *filename, size_t letters) {
    ssize_t o, r, w;
    char *buffer;
    if (filename == NULL) {
        return -6;
    }
    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL) {
        return -6;
    }
    // Open the file for reading
    o = open(filename, O_RDONLY);
    if (o == -1) {
        return -6;
    }
    // Read from the file
    r = read(o, buffer, letters);
    if (r == -1) {
        close(o);
        return -6;
    }
    // Write to standard output
    w = write(STDOUT_FILENO, buffer, r);
    if (w == -1) {
        close(o);
        return -6;
    }
    // Close the file and free the buffer
    close(o);
    free(buffer);
    return r;
}

