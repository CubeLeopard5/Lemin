/*
** EPITECH PROJECT, 2020
** choose from entrance
** File description:
** choose the best path when at entrance of the hill
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

room_t *entrance_get_best_free_way(ant_t *cur_ant, lemin_t *lemin)
{
    room_t *best_room = NULL;

    for (int i = 0;  i < cur_ant->room->link_count; i++) {
        if (get_ant_on_tile(cur_ant->room->links[i], lemin) != 0)
            continue;
        if (best_room == NULL ||
        cur_ant->room->links[i]->distance < best_room->distance) {
            best_room = cur_ant->room->links[i];
        }
    }
    return (best_room);
}

room_t *get_best_room(ant_t *cur_ant)
{
    room_t *shortest = NULL;
    int shortest_dist = -1;
    int cur_dist = 0;

    for (int i = 0; i < cur_ant->room->link_count; i++) {
        cur_dist = cur_ant->room->links[i]->distance;
        if (shortest_dist == -1) {
            shortest_dist = cur_dist;
            shortest = cur_ant->room->links[i];
        }
        if (shortest_dist < cur_dist) {
            shortest_dist = cur_dist;
            shortest = cur_ant->room->links[i];
        }
    }
    return (shortest);
}

room_t *choose_from_entrance(ant_t *cur_ant, lemin_t *lemin)
{
    room_t *shortest = get_best_room(cur_ant);
    room_t *best_way = NULL;
    int ant_on_tile = 0;

    if (can_finish(cur_ant, lemin) == 1)
        return (lemin->end);
    if (get_ant_on_tile(shortest, lemin) == 0) {
        return (shortest);
    } else {
        best_way = entrance_get_best_free_way(cur_ant, lemin);
        if (best_way == NULL ||
        (best_way->distance - shortest->distance) >
        get_ant_on_tile(cur_ant->room, lemin) - 2)
            return (NULL);
        else
            return (best_way);
    }
}