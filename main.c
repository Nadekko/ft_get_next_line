/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:31:25 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/28 20:05:13 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	int		fd2;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	if (fd == -1)
		printf("error");
	if (fd2 == -1)
		printf("error");
	char *str = get_next_line(fd);
	char *str2 = get_next_line(fd2);
	while (str)
	{
		printf("line = %s", str);
		free(str);
		str = get_next_line(fd);
	}
	printf("\n======================\n");
	while (str2)
	{
		printf("line = %s", str2);
		free(str2);
		str2 = get_next_line(fd2);
	}
	free(str2);
	free(str);
	close(fd);
	return (0);
}
