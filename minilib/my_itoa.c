/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_itoa.c
*/

#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// write nbr in a char *
// returned char * is dynamically allocated, it needs to be freed
// returns NULL if malloc fails
char *my_itoa(long nbr)
{
    int is_neg = nbr < 0;
    int i = 0;
    char *cnbr = malloc(sizeof(char) * (ML_ITOA_BUFSIZE + 1));

    if (cnbr == NULL)
        return (NULL);
    if (nbr == 0)
        cnbr[i++] = '0';
    if (is_neg)
        nbr *= -1;
    for (; nbr != 0 && i < ML_ITOA_BUFSIZE; nbr /= 10, ++i)
        cnbr[i] = nbr % 10 + '0';
    if (is_neg)
        cnbr[i++] = '-';
    cnbr[i] = '\0';
    my_revstr(cnbr);
    return (cnbr);
}

// write unsigned nbr in a char *
// returned char * is dynamically allocated, it needs to be freed
// returns NULL if malloc fails
char *my_uitoa(unsigned long nbr)
{
    int i = 0;
    char *cnbr = malloc(sizeof(char) * (ML_ITOA_BUFSIZE + 1));

    if (cnbr == NULL)
        return (NULL);
    if (nbr == 0) {
        cnbr[i++] = '0';
    }
    for (; nbr != 0 && i < ML_ITOA_BUFSIZE; nbr /= 10, ++i)
        cnbr[i] = nbr % 10 + '0';
    cnbr[i] = '\0';
    my_revstr(cnbr);
    return (cnbr);
}