#include "get_next_line.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *s3;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    s3 = malloc(sieof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)
    if (!s3)
        return (NULL);
    while (s1[i] != '\0')
        s3[j++]  = s1[i++];
    i = 0;
    while (s2[i] != '\0')
        s3[j++] = s2[i++];
    s3[j] = '\0';
    return (s3);
}

char    *ft_strrchr(const char *str, int c)
{
    char  *ptr;

    ptr = (char *)str;
    while (*ptr != c && *ptr != 0)
        ptr++;
    if (*ptr == c)
        return (ptr);
    else
        return (NULL);
}

size_t  ft_strlen(char *str)
{
    size_t  len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len)
}