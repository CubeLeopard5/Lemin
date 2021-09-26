/*
** EPITECH PROJECT, 2020
** path finding algo
** File description:
** algo for pathfinding
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int all_room_indexed(lemin_t *lemin)
{
    room_arr_t *arr;

    *(&arr) = *(&lemin->arr);
    while (arr != NULL) {
        if (arr->room->distance == 0) {
            return (84);
        }
        arr = arr->next;
    }
    return (0);
}

int algo(lemin_t *lemin)
{
    room_indexer(lemin);
    if (all_room_indexed(lemin) == 84)
        return (84);
    while (ant_path(lemin) == 1);
    return (0);
}