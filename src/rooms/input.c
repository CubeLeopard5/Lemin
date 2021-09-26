/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** input.c
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

void cat_to_buffer(char **buffer, char *str)
{
    unsigned long length = my_strlen(*buffer) + my_strlen(str);
    char *nbuf = malloc(sizeof(char) * (length + 2));

    if (nbuf == NULL)
        return;
    nbuf[0] = '\0';
    my_strcat(nbuf, *buffer);
    my_strcat(nbuf, "\n");
    my_strcat(nbuf, str);
    free(*buffer);
    *buffer = nbuf;
}

void append_to_buffer(char **buffer, char *str)
{
    if (*buffer) {
        cat_to_buffer(buffer, str);
    } else {
        *buffer = my_strdup(str);
    }
}