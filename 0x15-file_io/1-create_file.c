#include "main.h"

/**
 * create_file - Creates a file.
 */



int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        return -1;
    }

    if (text_content != NULL) {
        ssize_t len = strlen(text_content);
        ssize_t n = write(fd, text_content, len);
        if (n == -1 || n < len) {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}

