#include "shell.h"

char *_strncpy(char *dest, char *src, int n)
{
    int i;
    char *s = dest;

    for (i = 0; src[i] != '\0' && i < n - 1; i++)
        dest[i] = src[i];
    
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    
    return s;
}

char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    for (i = 0; dest[i] != '\0'; i++);

    for (j = 0; src[j] != '\0' && j < n; j++, i++)
        dest[i] = src[j];

    dest[i] = '\0';

    return s;
}

char *_strchr(char *s, char c)
{
    do {
        if (*s == c)
            return s;
    } while (*s++ != '\0');

    return NULL;
}
