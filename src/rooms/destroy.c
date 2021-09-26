/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** destroy.c
*/

#include "structs.h"
#include <stdlib.h>
#include <stddef.h>

void destroy_room(room_t *room)
{
    if (room == NULL)
        return;
    if (room->name)
        free(room->name);
    if (room->links)
        free(room->links);
    free(room);
}

void destroy_room_arr(room_arr_t *room_arr)
{
    room_arr_t *last = NULL;

    while (room_arr != NULL) {
        destroy_room(room_arr->room);
        last = room_arr;
        room_arr = room_arr->next;
        free(last);
    }
}