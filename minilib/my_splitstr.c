/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** my_splitstr.c
*/

#include "minilib.h"
#include <stdlib.h>
#include <stddef.h>

// count how many elements we will get in the list
unsigned int cnt_splt_elems(char *str, char delim)
{
    unsigned int count = 1;

    for (unsigned int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == delim)
            count += 1;
    }
    return (count);
}

// split str into a list, delimited by delim
char **my_splitstr(char *str, char delim)
{
    unsigned int i = 0;
    unsigned int start = 0;
    unsigned int count = cnt_splt_elems(str, delim);
    char **arr = malloc(sizeof(char *) * (count + 1));

    if (arr == NULL)
        return (NULL);
    for (unsigned int e = 0; e < count; ++e) {
        for (; str[i] != '\0' && str[i] != delim; ++i);
        arr[e] = malloc(sizeof(char) * ((i - start) + 1));
        if (arr[e] == NULL)
            return (NULL);
        my_strncpy(arr[e], &str[start], i - start);
        arr[e][i - start] = '\0';
        ++i;
        start = i;
    }
    arr[count] = NULL;
    return (arr);
}

// destroy a char ** (ending with a NULL element)
void destroy_list(char **arr)
{
    if (arr == NULL)
        return;
    for (unsigned int i = 0; arr[i] != NULL; ++i)
        free(arr[i]);
    free(arr);
}

// count how many elements are in a list
unsigned int count_list(char **arr)
{
    unsigned int count = 0;

    if (arr != NULL)
        for (; arr[count] != NULL; ++count);
    return (count);
}
