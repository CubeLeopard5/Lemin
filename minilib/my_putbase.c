/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putbase.c
*/

#include "minilib.h"

// write nbr in hexadecimal to stdout
void my_puthex(unsigned long nbr, bool uppercase)
{
    if (nbr > 15)
        my_puthex(nbr / 16, uppercase);
    my_putchar(uppercase ? HEX_UPPC[nbr % 16] : HEX_LOWC[nbr % 16]);
}

// write nbr in given base to stdout
void my_putbase(unsigned long nbr, char *base)
{
    unsigned long base_len = my_strlen(base);

    if (nbr > base_len - 1)
        my_putbase(nbr / base_len, base);
    my_putchar(base[nbr % base_len]);
}

// write nbr in hexadecimal to fd
void my_fputhex(int fd, unsigned long nbr, bool uppercase)
{
    if (nbr > 15)
        my_fputhex(fd, nbr / 16, uppercase);
    my_fputchar(fd, uppercase ? HEX_UPPC[nbr % 16] : HEX_LOWC[nbr % 16]);
}

// write nbr in given base to fd
void my_fputbase(int fd, unsigned long nbr, char *base)
{
    unsigned long base_len = my_strlen(base);

    if (nbr > base_len - 1)
        my_fputbase(fd, nbr / base_len, base);
    my_fputchar(fd, base[nbr % base_len]);
}