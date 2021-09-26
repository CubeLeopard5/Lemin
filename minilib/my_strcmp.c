/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_strcmp.c
*/

#include "minilib.h"

// compare two strings
// return 0 if they match
// return s1[i] - s2[i] if characters at position i differ
int my_strcmp(char *s1, char *s2)
{
    unsigned long i = 0;

    for (; s1[i] != '\0' || s2[i] != '\0'; ++i) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}

// compare two strings up to n characters from the beginning
// return 0 if they match
// return s1[i] - s2[i] if characters at position i differ
int my_strncmp(char *s1, char *s2, unsigned long n)
{
    unsigned long i = 0;

    for (; (s1[i] != '\0' || s2[i] != '\0') && i < n; ++i) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}

// return true if str ends with pattern, false otherwise
bool str_endsw(char *str, char *pattern)
{
    unsigned int str_len = my_strlen(str);
    unsigned int pat_len = my_strlen(pattern);

    if (str_len < pat_len)
        return (0);
    return my_strcmp(&str[str_len - pat_len], pattern) ? false : true;
}

// return true if str starts with pattern, false otherwise
bool str_startsw(char *str, char *pattern)
{
    return my_strncmp(str, pattern, my_strlen(pattern)) ? false : true;
}
