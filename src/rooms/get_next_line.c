/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** get_next_line.c
*/

#include "rooms.h"
#include "minilib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// calculate length of whitespaces at the end of str
unsigned long end_whitespace_len(char *str)
{
    unsigned long i = my_strlen(str);
    unsigned long count = 0;
    char c = '\0';

    for (; i > 0; --i) {
        c = str[i - 1];
        if (c == ' ' || c == '\t' || c == '\n') {
            count += 1;
        } else {
            break;
        }
    }
    return (count);
}

void trim_str(char *str)
{
    unsigned long trim_len = my_strlen(str) - end_whitespace_len(str);

    str[trim_len] = '\0';
}

void trim_comment(char *str)
{
    char *ptr = my_strstr(str, "#");

    while (ptr) {
        if (ptr[1] != '#' || ptr != str) {
            *ptr = '\0';
            break;
        }
        ptr = my_strstr(&ptr[2], "#");
    }
}

char *get_sane_line(void)
{
    size_t n = 0;
    char *line = NULL;
    ssize_t line_len = getline(&line, &n, stdin);

    if (line && line_len > 0) {
        trim_comment(line);
        trim_str(line);
    }
    return line && line_len > 0 ? line : NULL;
}

char *get_next_line(void)
{
    char *line = get_sane_line();

    while (line) {
        if (my_strlen(line) == 0) {
            free(line);
            line = get_sane_line();
            continue;
        }
        break;
    }
    return line;
}