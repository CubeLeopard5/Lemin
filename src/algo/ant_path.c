/*
** EPITECH PROJECT, 2020
** ant path
** File description:
** ant movements
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int get_ant_on_tile(room_t *rooms, lemin_t *lemin)
{
    ant_t *cur_ant;
    int count = 0;

    *(&cur_ant) = *(&lemin->ants_arr);
    while (cur_ant != NULL)
    {
        if (my_strcmp(rooms->name, cur_ant->room->name) == 0) {
            count += 1;
        }
        cur_ant = cur_ant->next;
    }
    return (count);
}

void move_this_ant(ant_t *cur_ant, lemin_t *lemin)
{
    room_t *choice = NULL;
    int ant_on_tile = get_ant_on_tile(cur_ant->room, lemin);

    if (ant_on_tile > 1) {
        choice  = choose_from_entrance(cur_ant, lemin);
        if (choice != NULL) {
            move_ant(cur_ant, choice);
        }
        return;
    }
    choice = choose_best_path(cur_ant, lemin);
    if (choice != NULL) {
        move_ant(cur_ant, choice);
        return;
    }
}

int ant_path(lemin_t *lemin)
{
    ant_t *cur_ant;
    int has_moved = 0;

    *(&cur_ant) = *(&lemin->ants_arr);
    while (cur_ant != NULL)
    {
        if (my_strcmp(lemin->end->name, cur_ant->room->name) != 0) {
            if (cur_ant->room != NULL) {
                move_this_ant(cur_ant, lemin);
                has_moved = 1;
            }
        }
        cur_ant = cur_ant->next;
    }
    if (has_moved == 1) {
        my_putstr("\n");
        return (1);
    }
    return (has_moved);
}