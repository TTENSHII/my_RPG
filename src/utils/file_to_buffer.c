/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** file_to_buffer
*/

#include "rpg.h"
#include <fcntl.h>
#include <sys/stat.h>

char *file_to_buffer(const char *path)
{
    char *buffer = NULL;
    int filedescriptor = 0;
    int count = 0;
    struct stat statsize;

    filedescriptor = open(path, O_RDONLY);
    if (filedescriptor == -1) {
        write(1, "The file cannot be opened\n", 25);
        return (buffer);
    }
    stat(path, &statsize);
    count = statsize.st_size;
    buffer = malloc(sizeof(char) * count + 1);
    read(filedescriptor, buffer, count);
    buffer[count] = '\0';
    close(filedescriptor);
    return (buffer);
}
