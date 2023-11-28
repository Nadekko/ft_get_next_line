/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:34 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/28 20:07:50 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifdef BUFFER_SIZE
#  define MY_BUFFER_SIZE BUFFER_SIZE
# else
#  define MY_BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX FOPEN_MAX
# endif 

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);

#endif