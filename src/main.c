/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** main.c
*/

#include "structs.h"
#include "rooms.h"
#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

void display_rooms(lemin_t *lemin)
{
    room_arr_t *e = lemin->arr;

    my_putstr("#rooms\n");
    while (e) {
        if (e->room == lemin->start) {
            my_putstr("##start\n");
        } else if (e->room == lemin->end) {
            my_putstr("##end\n");
        }
        my_printf("%s %i %i\n", e->room->name, e->room->x, e->room->y);
        e = e->next;
    }
}

void reverse_room_arr(lemin_t *lemin)
{
    room_arr_t *e = lemin->arr;
    room_arr_t *new_next = NULL;
    room_arr_t *real_next = NULL;

    while (e) {
        real_next = e->next;
        e->next = new_next;
        new_next = e;
        if (real_next == NULL)
            lemin->arr = e;
        e = real_next;
    }

}

void display_game_info(lemin_t *lemin)
{
    reverse_room_arr(lemin);
    my_printf("#number_of_ants\n%i\n", lemin->ants);
    display_rooms(lemin);
    my_printf("#tunnels\n");
    if (lemin->input)
        my_printf("%s\n", lemin->input);
    my_putstr("#moves\n");
    free(lemin->input);
}

bool is_game_valid(lemin_t *lemin)
{
    bool valid = true;

    if (lemin->ants <= 0)
        valid = false;
    if (!lemin->start || !lemin->end)
        valid = false;
    if (lemin->input == NULL)
        valid = false;
    if (lemin->arr == NULL)
        valid = false;
    return valid;
}

int main(void)
{
    lemin_t lemin;
    int has_error = 0;

    load_lem_in(&lemin);
    display_game_info(&lemin);
    if (!is_game_valid(&lemin))
        return (84);
    has_error = algo(&lemin);
    destroy_room_arr(lemin.arr);
    return (has_error);
}