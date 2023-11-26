size_t  ft_strlen(char *str)
char    ft_strrcchr(const char *str, int c)
char    ft_strcat(char *dst, char *src)
char    ft_strcpy(char  *dst, char *src)
char    ft_stockat(char *stock, char *buffer, int  bytes_read)
char    ft_read(char *stock, int fd)

size_t  ft_strlen(char *str)
{
    size_t  len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len)
}

char    ft_strcpy(char  *dst, char *src)
{
    char *temp;

    temp = dst;
    while (*src != '\0')
        *dst++ = *src++;
    *dst = '\0';
    return (temp);
}

char    ft_strcat(char *dst, char *src)
{
    char    *ptr;

    ptr = dst + ft_strlen(dst);
    while (*src != '\0')
        *ptr++ = *src++;
    *ptr = '\0';
    return (dst)
}

char    ft_stockat(char *stock, char *buffer, int  bytes_read)
{
    char    *temp;

    temp = malloc(ft_strlen(stock) + bytes_read + 1);
    if (!temp || !stock || !buffer)
        return (NULL)
    ft_strcpy(temp, stock);
    ft_strcat(temp, buffer);
    free(stock);
    return (temp);
}

char    ft_strrcchr(const char *str, int c)
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

char    ft_read(char *stock, int fd)
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
        buffer = ft_stockat(stock, buffer, bytes_read);
        if (ft_strrchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return(stock)
}

char *get_next_line(int fd)
{
    static char    *buffer = NULL;
    char    *line;
    
    line = NULL;
    if (BUFFER__SIZE < 1 || fd < 0)
            return (NULL);
    buffer = ft_read(fd, buffer)
    /*

    */
    return (stock);
}
