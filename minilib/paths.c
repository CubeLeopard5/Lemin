/*
** EPITECH PROJECT, 2019
** minilib
** File description:
** paths.c
*/

#include "minilib.h"
#include <stddef.h>

// get a pointer to the start of the filename in path
char *get_filename(char *path)
{
    unsigned int i = my_strlen(path);
    int raise = 0;

    while (1) {
        if (path[i] == '/')
            break;
        if (i == 0)
            break;
        i -= 1;
        raise = 1;
    }
    if (raise)
        i += 1;
    return (&path[i]);
}

int is_slash_needed(char *path, char *append_path, int *path_len)
{
    if (path[*path_len - 1] == '/' && append_path[0] == '/') {
        while (path[*path_len - 1] == '/')
            *path_len -= 1;
    } else if (path[*path_len - 1] != '/' && append_path[0] != '/') {
        return (1);
    }
    return (0);
}

// append append_path after path, adding / removing slashes as needed
// this function statically allocates the returned char *
// it will be overwritten on the next call
char *append_to_path(char *path, char *append_path)
{
    int path_len = my_strlen(path);
    int append_len = my_strlen(append_path);
    int add_slash = is_slash_needed(path, append_path, &path_len);
    int new_len = path_len + append_len + add_slash;
    int g = 0;
    static char new_path[2048];

    if (path_len + append_len + 2 > 2048)
        return (NULL);
    for (int i = 0; i < path_len; ++i, ++g)
        new_path[g] = path[i];
    if (add_slash)
        new_path[g++] = '/';
    for (int i = 0; i < append_len; ++i, ++g)
        new_path[g] = append_path[i];
    new_path[new_len] = '\0';
    return (new_path);
}