/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strcat.c
*/

#include "minilib.h"

// append src at the end of dest
// buffer must have enough space for my_strlen(src) + 1
char *my_strcat(char *dest, char *src)
{
    unsigned long dest_i = my_strlen(dest);

    for (unsigned long i = 0; src[i] != '\0'; ++i, ++dest_i)
        dest[dest_i] = src[i];
    dest[dest_i] = '\0';
    return (dest);
}

// append up to n characters from src at the end of dest
// buffer must have enough space for my_strlen(src) + n + 1
char *my_strncat(char *dest, char *src, unsigned long n)
{
    unsigned long dest_i = my_strlen(dest);

    for (unsigned long i = 0; src[i] != '\0' && i < n; ++i, ++dest_i)
        dest[dest_i] = src[i];
    dest[dest_i] = '\0';
    return (dest);
}
