/*
** EPITECH PROJECT, 2020
** move ant
** File description:
** move_ant
*/

#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void move_ant(ant_t *cur_ant, room_t *room)
{
    cur_ant->room = room;
    my_putchar('P');
    my_putnbr(cur_ant->ant_nb);
    my_putchar('-');
    my_putstr(cur_ant->room->name);
    my_putchar(' ');
}

