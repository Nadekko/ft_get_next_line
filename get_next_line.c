/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:24:01 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/27 20:15:45 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (NULL);
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	next_line = NULL;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	/*if (buffer[i + 1] == '\0')
		return (NULL);*/
	next_line = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*ft_read(int fd, char *stock)
{
	char	*buffer;
	int		bytes_read;

	buffer = NULL;
	buffer = malloc(sizeof(char) * MY_BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stock, '\n'))
	{
		bytes_read = read(fd, buffer, MY_BUFFER_SIZE);
		printf("\n\nrv = %d\n", bytes_read);
		if (bytes_read < 1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || MY_BUFFER_SIZE < 1 || read(fd, &line, 0))
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	printf("\n\nstatic = %s\n\n", buffer);
	return (line);
}
