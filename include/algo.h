/*
** EPITECH PROJECT, 2020
** algo
** File description:
** algo
*/

#include "structs.h"

#ifndef ALGO_H_
#define ALGO_H_

int algo(lemin_t *lemin);
int ant_path(lemin_t *lemin);
room_t *choose_best_path(ant_t *cur_ant, lemin_t *lemin);
room_t *choose_from_entrance(ant_t *cur_ant, lemin_t *lemin);
int get_ant_on_tile(room_t *rooms, lemin_t *lemin);
room_t *get_best_free_way(ant_t *cur_ant, lemin_t *lemin);
void move_ant(ant_t *cur_ant, room_t *room);
void room_indexer(lemin_t *lemin);

#endif /* !ALGO_H_ */
