#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>


char	*get_next_line(int fd)
char    *ft_get_line(char *buffer)
char    *ft_next_line(char *buffer)
char    *ft_read(int fd, char *stock)

size_t  ft_strlen(char *str);
char    ft_strrchr(const char *str, int c);
char    ft_strjoin(const char *s1, const char *s2);
//char    ft_freebuff(char *stock, char *buffer);
//void    ft_calloc(size_t n_elem, size_t s_elem);
//void    ft_bzero(void *s, size_t n);

# endif