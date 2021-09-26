/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_printf.c
*/

#include "minilib.h"
#include <stdarg.h>

// handle unknown flag
void print_unhandled_flag(int fd, char format)
{
    my_fputchar(fd, '%');
    my_fputchar(fd, format);
}

// handle my_printf flags
bool my_printf_flag(int fd, char format, va_list *ap)
{
    switch (format) {
        case 'c': my_fputchar(fd, (char) va_arg(*ap, int));
            return true;
        case 's': my_fputstr(fd, va_arg(*ap, char *));
            return true;
        case 'i': my_fputnbr(fd, (long) va_arg(*ap, int));
            return true;
        case 'd': my_fputnbr(fd, (long) va_arg(*ap, int));
            return true;
        case 'u': my_fputunbr(fd, va_arg(*ap, unsigned long));
            return true;
        case 'x': my_fputhex(fd, va_arg(*ap, unsigned long), false);
            return true;
        case 'X': my_fputhex(fd, va_arg(*ap, unsigned long), true);
            return true;
        case 'p': my_fputptr(fd, va_arg(*ap, unsigned long));
            return true;
        default: print_unhandled_flag(fd, format);
            return false;
    }
}

// print format to stdout replacing specific format flags with values
// passed as parameters (in order)
// %c      print a char
// %s      print a char *
// %i, %d  print a signed number
// %u      print an unsigned number
// %x      print a hexadecimal number (lowercase)
// %X      print a hexadecimal number (uppercase)
// %p      print a pointer in its hexadecimal value
// unknown flags will be printed as is
int my_printf(char const *format, ...)
{
    va_list ap;
    int r = 0;

    va_start(ap, format);
    for (; *format != '\0'; ++format) {
        if (*format == '%') {
            r += my_printf_flag(F_STDOUT, *(++format), &ap) ? 1 : 0;
        } else {
            my_putchar(*format);
        }
    }
    va_end(ap);
    return r;
}

// print format to fd replacing specific format flags with values
// passed as parameters (in order)
// %c      print a char
// %s      print a char *
// %i, %d  print a signed number
// %u      print an unsigned number
// %x      print a hexadecimal number (lowercase)
// %X      print a hexadecimal number (uppercase)
// %p      print a pointer in its hexadecimal value
// unknown flags will be printed as is
int my_fprintf(int fd, char const *format, ...)
{
    va_list ap;
    int r = 0;

    va_start(ap, format);
    for (; *format != '\0'; ++format) {
        if (*format == '%') {
            r += my_printf_flag(fd, *(++format), &ap) ? 1 : 0;
        } else {
            my_fputchar(fd, *format);
        }
    }
    va_end(ap);
    return r;
}
