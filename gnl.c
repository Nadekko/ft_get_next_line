#include "get_next_line.h"

char    *ft_get_line(char *buffer)
{
    int i;
    char    *line;

    i = 0;
    line = NULL;
    if (!buffer)
        return (NULL);
    while (buffer[i] && buffer[i] != '\n' )
        i++;
    line = malloc(sizeof(char) * i + 2);
    (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        line[i++] = '\n';
    line[i + 1] = '\0';
    return (line);
}

char    *ft_next_line(char *buffer)
{
    int i;
    char    *next_line;

    i = 0;
    next_line = NULL;
    if (!buffer)
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    next_line = malloc(sizeof(char) * i + 1);
    if (!next_line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        next_line[i] = buffer[i];
        i++;
    }
    next_line[i] = '\0';
    return (next_line);
}


char    *ft_read(int fd, char *stock)
{
    char    *buffer;
    int     bytes_read;

    if (!stock)
        return (NULL);
    buffer = malloc(BUFFER__SIZE + 1);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER__SIZE);
        if (bytes_read == -1)
        {
            free(buffer)
            return (NULL)
        }
        buffer[bytes_read] = '\0';
        buffer = ft_strjoin(stock, buffer);
        if (ft_strrchr(buffer, '\n'))
            break;
    }
    free(stock);
    return(buffer)
}

char *get_next_line(int fd)
{
    static char    *buffer = NULL;
    char    *line;
    
    line = NULL;
    if (BUFFER_SIZE < 1 || fd < 0)
            return (NULL);
    buffer = ft_read(fd, buffer);
    line = ft_get_line(buffer);
    buffer = ft_next_line(buffer);
    return (line);
}

/*char    ft_freebuff(char *stock, char *buffer)
{
    char    *temp;

    temp = ft_strjoin(stock, buffer);
    free(buffer);
    return(temp);
}

void    ft_calloc(size_t n_elem, size_t s_elem)
{
    char    *res;

    temp = malloc(n_elem * s_elem);
    if (!res)
        return (NULL);
    ft_bzero(res, n_elem * s_elem);
    return (res);
}

void    ft_bzero(void *s, size_t n)
{
    unsigned char   *ptr;

    ptr = s;
    while (n > 0)
    {
        *ptr++ = 0;
        n--;
    }
}*/
