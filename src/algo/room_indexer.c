/*
** EPITECH PROJECT, 2020
** room indexer
** File description:
** room_indexer
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void index_neighbors(room_t *room, int cur_level)
{
    for (int i = 0; i < room->link_count; i++) {
        if (room->links[i]->distance == 0 ||
        room->links[i]->distance > cur_level + 1)
            room->links[i]->distance = cur_level + 1;
    }
}

int index_this_level(room_arr_t *arr, int cur_level)
{
    int is_finished = 0;

    while (arr != NULL) {
        if (arr->room->distance == cur_level) {
            index_neighbors(arr->room, cur_level);
        }
        if (arr->room->distance == 0) {
            is_finished = 1;
        }
        arr = arr->next;
    }
    return (is_finished);
}

void room_indexer(lemin_t *lemin)
{
    lemin->room_distance = 1;
    lemin->end->distance = 1;

    for (int i = 0; i < 100; i++) {
        if (index_this_level(lemin->arr, lemin->room_distance) == 0)
            break;
        lemin->room_distance += 1;
    }
}