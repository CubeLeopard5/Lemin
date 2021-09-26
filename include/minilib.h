/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** minilib.h
*/

#ifndef __MINILIB_H__
#define __MINILIB_H__

#include <stdbool.h>

#define HEX_LOWC "0123456789abcdef"
#define HEX_UPPC "0123456789ABCDEF"

#define F_STDIN (0)
#define F_STDOUT (1)
#define F_STDERR (2)

#define ML_ITOA_BUFSIZE (32)

// my_atoi.c
long my_atoi(char *str);
unsigned long my_atoui(char *str);

// my_itoa.c
char *my_itoa(long nbr);
char *my_uitoa(unsigned long nbr);

// my_printf.c
int my_printf(char const *format, ...);
int my_fprintf(int fd, char const *format, ...);

// my_putbase.c
void my_puthex(unsigned long nbr, bool uppercase);
void my_putbase(unsigned long nbr, char *base);
void my_fputhex(int fd, unsigned long nbr, bool uppercase);
void my_fputbase(int fd, unsigned long nbr, char *base);

// my_putchar.c
void my_putchar(char c);
void my_fputchar(int fd, char c);

// my_putnbr.c
void my_putnbr(long nbr);
void my_putunbr(unsigned long nbr);
void my_fputnbr(int fd, long nbr);
void my_fputunbr(int fd, unsigned long nbr);

// my_putptr.c
void my_fputptr(int fd, unsigned long ptr);
void my_putptr(unsigned long ptr);

// my_putstr.c
void my_putstr(char *str);
void my_fputstr(int fd, char *str);

// my_revstr.c
char *my_revstr(char *str);

// my_splitstr.c
char **my_splitstr(char *str, char delim);
void destroy_list(char **arr);
unsigned int count_list(char **arr);

// my_strcat.c
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char *src, unsigned long n);

// my_strcmp.c
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, unsigned long n);
bool str_endsw(char *str, char *pattern);
bool str_startsw(char *str, char *pattern);

// my_strcpy.c
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, unsigned long n);

// my_strdup.c
char *my_strdup(char *src);

// my_strlen.c
unsigned long my_strlen(char *str);

// my_strstr.c
char *my_strstr(char *str, char *to_find);

// paths.c
char *get_filename(char *path);
char *append_to_path(char *path, char *append_path);

#endif