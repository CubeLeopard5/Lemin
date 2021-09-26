/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_atoi.c
*/

#include "minilib.h"

// convert str to long
long my_atoi(char *str)
{
    unsigned long size = my_strlen(str);
    unsigned int multiplier = 1;
    long nbr = 0;
    int offset = *str == '-';

    for (int i = size - 1; i >= 0 + offset; --i, multiplier *= 10) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        nbr += (str[i] - '0') * multiplier;
    }
    if (offset == 1)
        nbr *= -1;
    return (nbr);
}

// convert str to unsigned long
unsigned long my_atoui(char *str)
{
    unsigned long multiplier = 1;
    unsigned long nbr = 0;
    unsigned long size = my_strlen(str);

    for (int i = size - 1; i >= 0; --i, multiplier *= 10) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        nbr += (str[i] - '0') * multiplier;
    }
    return (nbr);
}