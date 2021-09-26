/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** create.c
*/

#include "structs.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// create room with name
room_t *create_room(char *name)
{
    char *dup_name = my_strdup(name);
    room_t *room = malloc(sizeof(room_t));

    if (room == NULL || dup_name == NULL)
        return (NULL);
    room->name = dup_name;
    room->link_count = 0;
    room->links = NULL;
    room->x = 0;
    room->y = 0;
    room->distance = 0;
    return (room);
}

// append room to array
void append_room_arr(lemin_t *lemin, room_t *room)
{
    room_arr_t *element = malloc(sizeof(room_arr_t));

    element->room = room;
    element->next = lemin->arr;
    lemin->arr = element;
}

// initialize lemin with default values
void init_default_lemin(lemin_t *lemin)
{
    lemin->ants = 0;
    lemin->arr = NULL;
    lemin->start = NULL;
    lemin->end = NULL;
    lemin->input = NULL;
    lemin->valid = true;
}