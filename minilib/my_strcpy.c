/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strcpy.c
*/

#include "minilib.h"

// copy contents of src to dest
char *my_strcpy(char *dest, char *src)
{
    unsigned long i = 0;

    for (; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

// copy n characters (from the beginning) from src to dest
char *my_strncpy(char *dest, char *src, unsigned long n)
{
    unsigned long i = 0;
    unsigned long src_len = my_strlen(src);

    for (; i < n; ++i) {
        if (src_len < n && i >= src_len) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
    }
    return (dest);
}
