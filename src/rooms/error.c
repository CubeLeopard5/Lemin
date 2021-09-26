/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** error.c
*/

#include "minilib.h"

// determine if line is a room
int is_line_room(char *line)
{
    int spaces = 0;

    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] != ' ' && line[i] < '0' && line[i] > '9')
            return (0);
        spaces += line[i] == ' ' ? 1 : 0;
    }
    return (spaces == 2);
}

// determine if line is a tunnel
int is_line_tunnel(char *line)
{
    int dashes = 0;

    for (int i = 0; line[i] != '\0'; ++i) {
        dashes += line[i] == '-' ? 1 : 0;
    }
    return (dashes == 1);
}

// verify that the line is valid
int is_line_valid(char *line)
{
    if (!my_strcmp(line, "##start") || !my_strcmp(line, "##end")) {
        return (1);
    } else {
        return (is_line_room(line) || is_line_tunnel(line));
    }
}