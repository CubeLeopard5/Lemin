/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putnbr.c
*/

#include "minilib.h"

// write nbr in decimal to stdout
void my_putnbr(long nbr)
{
    if (nbr > 9 || nbr < -9)
        my_putnbr(nbr / 10);
    if (nbr < 0) {
        nbr *= -1;
        if (nbr % 10 > 0 && nbr / 10 == 0)
            my_putchar('-');
    }
    my_putchar(nbr % 10 + '0');
}

// write unsigned nbr in decimal to stdout
void my_putunbr(unsigned long nbr)
{
    if (nbr > 9)
        my_putunbr(nbr / 10);
    my_putchar(nbr % 10 + '0');
}

// write nbr in decimal to fd
void my_fputnbr(int fd, long nbr)
{
    if (nbr > 9 || nbr < -9)
        my_fputnbr(fd, nbr / 10);
    if (nbr < 0) {
        nbr *= -1;
        if (nbr % 10 > 0 && nbr / 10 == 0)
            my_fputchar(fd, '-');
    }
    my_fputchar(fd, nbr % 10 + '0');
}

// write unsigned nbr in decimal to fd
void my_fputunbr(int fd, unsigned long nbr)
{
    if (nbr > 9)
        my_fputunbr(fd, nbr / 10);
    my_fputchar(fd, nbr % 10 + '0');
}
