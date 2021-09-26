/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** ants.c
*/

#include "rooms.h"
#include <stdlib.h>
#include <stddef.h>

void set_ants_to_start(lemin_t *lemin)
{
    ant_t *cur_ant;

    *(&cur_ant) = *(&lemin->ants_arr);
    while (cur_ant != NULL)
    {
        cur_ant->room = lemin->start;
        cur_ant = cur_ant->next;
    }
}

int add_ant_to_arr(ant_t **arr)
{
    ant_t *ant = malloc(sizeof(ant_t));

    if (ant == NULL)
        return (0);
    ant->ant_nb = 0;
    ant->room = NULL;
    ant->next = *arr;
    *arr = ant;
    return (1);
}

// create a linked list of ants
ant_t *create_ants(int amount)
{
    ant_t *arr = NULL;

    while (amount > 0) {
        if (!add_ant_to_arr(&arr))
            return (NULL);
        arr->ant_nb = amount--;
    }
    return (arr);
}

// destroy linked list
void destroy_ants(ant_t *arr)
{
    ant_t *element = arr;
    ant_t *next = NULL;

    while (element != NULL) {
        next = element->next;
        free(element);
        element = next;
    }
}