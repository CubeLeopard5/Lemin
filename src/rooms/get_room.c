/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** get_room.c
*/

#include "structs.h"
#include "minilib.h"
#include <stddef.h>

// get room by its name
room_t *get_room(room_arr_t *arr, char *name)
{
    while (arr != NULL) {
        if (!my_strcmp(arr->room->name, name))
            return (arr->room);
        arr = arr->next;
    }
    return (NULL);
}