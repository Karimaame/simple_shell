#include "shell.h"

/**
 * _custom_strlen - calculates the length of a string
 * @s: the input string to measure
 *
 * Return: an integer representing the string's length
 */
int _custom_strlen(char *s)
{
    int length = 0;

    if (!s)
        return (0);

    while (*s++)
        length++;

    return (length);
}

/**
 * _custom_strcmp - performs a lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a negative value if s1 < s2, a positive value if s1 > s2, and 0 if s1 == s2
 */
int _custom_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);

        s1++;
        s2++;
    }

    if (*s1 == *s2)
        return (0);
    else
        return (*s1 < *s2 ? -1 : 1);
}

/**
 * _custom_starts_with - checks if the 'needle' starts with the 'haystack'
 * @haystack: the string to search within
 * @needle: the substring to find
 *
 * Return: a pointer to the next character of 'haystack' or NULL if not found
 */
char *_custom_starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return (NULL);

    return ((char *)haystack);
}

/**
 * _custom_strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: a pointer to the destination buffer
 */
char *_custom_strcat(char *dest, char *src)
{
    char *result = dest;

    while (*dest)
        dest++;

    while (*src)
        *dest++ = *src++;

    *dest = *src;

    return (result);
}
