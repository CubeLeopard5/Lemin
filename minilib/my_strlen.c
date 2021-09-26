/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strlen.c
*/

// count char * len (excluding the trailing \0)
unsigned long my_strlen(char *str)
{
    unsigned long l = 0;

    for (; str[l] != '\0'; ++l);
    return l;
}