/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putchar.c
*/

#include "minilib.h"
#include <unistd.h>

// write a character to stdout
void my_putchar(char c)
{
    write(F_STDOUT, &c, 1);
}

// write a character to fd
void my_fputchar(int fd, char c)
{
    write(fd, &c, 1);
}
