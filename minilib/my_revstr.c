/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_revstr.c
*/

#include "minilib.h"

// reverse str
char *my_revstr(char *str)
{
    unsigned long len = my_strlen(str);
    char temp_str[len];

    my_strcpy(temp_str, str);
    for (unsigned long i = 0; i < len; ++i)
        str[i] = temp_str[len - 1 - i];
    return (str);
}