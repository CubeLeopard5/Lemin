/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** rooms.h
*/

#ifndef __ROOMS_H__
#define __ROOMS_H__

#include "algo.h"
#include "structs.h"

// connect.c
void connect_rooms(room_t *room1, room_t *room2);

// create.c
room_t *create_room(char *name);
void append_room_arr(lemin_t *lemin, room_t *room);
void init_default_lemin(lemin_t *lemin);

// destroy.c
void destroy_room_arr(room_arr_t *room_arr);
void destroy_room(room_t *room);

// get_room.c
room_t *get_room(room_arr_t *arr, char *name);

// parser.c
void load_lem_in(lemin_t *lemin);

// error.c
int is_line_room(char *line);
int is_line_tunnel(char *line);
int is_line_valid(char *line);

// ants.c
ant_t *create_ants(int amount);
void destroy_ants(ant_t *arr);
void set_ants_to_start(lemin_t *lemin);

// input.c
void cat_to_buffer(char **buffer, char *str);
void append_to_buffer(char **buffer, char *str);

// get_next_line.c
char *get_next_line(void);

#endif
