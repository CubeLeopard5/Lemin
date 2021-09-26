/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** connect.c
*/

#include "structs.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

int room_already_connected(room_t *room1, room_t *room2)
{
    if (!room1 || !room2)
        return (1);
    for (int i = 0; i < room1->link_count; ++i) {
        if (!my_strcmp(room1->links[i]->name, room2->name))
            return (1);
    }
    return (0);
}

void connect_rooms(room_t *room1, room_t *room2)// link room2 to room1
{
    room_t **nlinks = NULL;

    if (room_already_connected(room1, room2))
        return;
    nlinks = malloc(sizeof(room_t) * (room1->link_count + 1));
    if (nlinks == NULL)
        return;
    for (int i = 0; i < room1->link_count; ++i)
        nlinks[i] = room1->links[i];
    nlinks[room1->link_count] = room2;
    room1->link_count += 1;
    if (room1->links)
        free(room1->links);
    room1->links = nlinks;
}