/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_putptr.c
*/

#include "minilib.h"

// write pointer value in hex to fd
void my_fputptr(int fd, unsigned long ptr)
{
    if (ptr == 0) {
        my_fputstr(fd, "(nil)");
    } else {
        my_fputstr(fd, "0x");
        my_fputhex(fd, ptr, false);
    }
}

// write pointer value in hex to stdout
void my_putptr(unsigned long ptr)
{
    if (ptr == 0) {
        my_putstr("(nil)");
    } else {
        my_putstr("0x");
        my_puthex(ptr, false);
    }
}