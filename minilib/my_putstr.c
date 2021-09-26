/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putstr.c
*/

#include "minilib.h"
#include <unistd.h>

// print str to stdout
void my_putstr(char *str)
{
    write(F_STDOUT, str, my_strlen(str));
}

// print str to fd
void my_fputstr(int fd, char *str)
{
    write(fd, str, my_strlen(str));
}