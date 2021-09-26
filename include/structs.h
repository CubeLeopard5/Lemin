/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** structs.h
*/

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <stdbool.h>

typedef struct room_s {
    char *name;             // nom de la pièce
    int x;                  // coordonnée x
    int y;                  // coordonnée y
    int distance;           // distance
    int link_count;         // nombre de links
    struct room_s **links;  // array de room_t liées à celle-ci
} room_t;

typedef struct ant_s {
    int ant_nb;         // ant number
    room_t *room;       // room where the ant is
    struct ant_s *next; // ptr to next ant
} ant_t;

typedef struct room_arr_s {
    room_t *room;               // room
    struct room_arr_s *next;    // next room
} room_arr_t;

typedef struct lemin_s {
    int room_distance;
    int ants;         // number of ants
    ant_t *ants_arr;  // actual ants
    room_t *start;    // start room
    room_t *end;      // end room
    room_arr_t *arr;  // linked list of all rooms
    char *input;      // input file contents
    bool valid;       // is input valid
} lemin_t;

#endif
