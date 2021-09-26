/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** parser.c
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void parse_line(char *line, lemin_t *lemin)
{
    char **split = my_splitstr(line, is_line_room(line) ? ' ' : '-');
    room_t *room = NULL;
    room_t *room2 = NULL;

    if (is_line_room(line) && count_list(split) == 3) {
        room = create_room(split[0]);
        room->x = my_atoi(split[1]);
        room->y = my_atoi(split[2]);
        append_room_arr(lemin, room);
    } else if (is_line_tunnel(line) && count_list(split) == 2) {
        room = get_room(lemin->arr, split[0]);
        room2 = get_room(lemin->arr, split[1]);
        connect_rooms(room, room2);
        connect_rooms(room2, room);
        append_to_buffer(&lemin->input, line);
    } else {
        lemin->valid = false;
    }
    destroy_list(split);
}

void parse_keep(lemin_t *lemin, bool start)
{
    char *next_line = get_next_line();

    while (next_line) {
        parse_line(next_line, lemin);
        if (is_line_room(next_line))
            break;
        free(next_line);
        next_line = get_next_line();
    }
    if (!next_line)
        return;
    if (start && !lemin->start) {
        lemin->start = lemin->arr->room;
    } else if (!start && !lemin->end) {
        lemin->end = lemin->arr->room;
    } else {
        lemin->valid = false;
    }
    free(next_line);
}

int load_ants(lemin_t *lemin)
{
    char *line = get_next_line();

    if (line == NULL) {
        lemin->valid = false;
        return (0);
    }
    for (unsigned long i = 0; line[i]; ++i) {
        if (line[i] < '0' || line[i] > '9')
            lemin->valid = false;
    }
    lemin->ants = my_atoi(line);
    free(line);
    return (lemin->ants > 0);
}

void load_lem_in(lemin_t *lemin)
{
    char *line = NULL;

    init_default_lemin(lemin);
    if (!load_ants(lemin))
        return;
    line = get_next_line();
    while (line != NULL && lemin->valid) {
        if (!is_line_valid(line)) {
            break;
        } else if (!my_strcmp(line, "##start") || !my_strcmp(line, "##end")) {
            parse_keep(lemin, !my_strcmp(line, "##start") ? true : false);
        } else {
            parse_line(line, lemin);
        }
        free(line);
        line = get_next_line();
    }
    lemin->ants_arr = create_ants(lemin->ants);
    set_ants_to_start(lemin);
}