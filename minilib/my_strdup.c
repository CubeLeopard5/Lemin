/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strdup.c
*/

#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// duplicate a char array
char *my_strdup(char *src)
{
    unsigned long src_len = my_strlen(src);
    char *dup = malloc(sizeof(char) * (src_len + 1));

    if (dup == NULL)
        return (NULL);
    for (unsigned long i = 0; i < src_len; ++i)
        dup[i] = src[i];
    dup[src_len] = '\0';
    return (dup);
}