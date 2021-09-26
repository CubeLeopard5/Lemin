/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strstr.c
*/

#include "minilib.h"
#include <stddef.h>

// return pointer of the first occurence of to_find in str
// returns NULL if nothing is found
char *my_strstr(char *str, char *to_find)
{
    unsigned long str_pos = 0;
    unsigned long find_len = my_strlen(to_find);
    unsigned long find_pos = 0;

    while (str[str_pos] != '\0') {
        if (str[str_pos] != to_find[find_pos])
            find_pos = 0;
        if (str[str_pos] == to_find[find_pos])
            find_pos += 1;
        str_pos += 1;
        if (find_len == find_pos)
            return &str[str_pos - find_pos];
    }
    return (NULL);
}