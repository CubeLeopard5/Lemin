/*
** EPITECH PROJECT, 2020
** choose best path
** File description:
** choose the best
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int can_finish(ant_t *cur_ant, lemin_t *lemin)
{
    for (int i = 0; i < cur_ant->room->link_count; i++) {
        if (my_strcmp(cur_ant->room->links[i]->name, lemin->end->name) == 0)
            return (1);
    }
    return (0);
}

room_t *get_best_free_way(ant_t *cur_ant, lemin_t *lemin)
{
    room_t *best_room = NULL;

    for (int i = 0;  i < cur_ant->room->link_count; i++) {
        if (get_ant_on_tile(cur_ant->room->links[i], lemin) != 0) {
            continue;
        }
        if (best_room == NULL ||
        cur_ant->room->links[i]->distance < best_room->distance) {
            best_room = cur_ant->room->links[i];
        }
    }
    return (best_room);
}

room_t *get_only_way(ant_t *cur_ant, lemin_t *lemin)
{
    if (cur_ant->room->links[0]->distance <= cur_ant->room->links[1]->distance
    && get_ant_on_tile(cur_ant->room->links[0], lemin) == 0)
        return (cur_ant->room->links[0]);
    else if (get_ant_on_tile(cur_ant->room->links[1], lemin) == 0)
        return (cur_ant->room->links[1]);
    else
        return (NULL);
}

room_t *choose_best_path(ant_t *cur_ant, lemin_t *lemin)
{
    room_t *best_way = NULL;
    room_t *shortest = get_best_free_way(cur_ant, lemin);

    if (can_finish(cur_ant, lemin) == 1)
        return (lemin->end);
    if (cur_ant->room->link_count == 2)
        return (get_only_way(cur_ant, lemin));
    best_way = get_best_free_way(cur_ant, lemin);
    if (best_way != NULL && (best_way->distance - shortest->distance) <= 1)
        return (best_way);
    return (NULL);
}
