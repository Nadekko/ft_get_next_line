/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:31:25 by andjenna          #+#    #+#             */
/*   Updated: 2023/11/27 20:06:40 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;

	fd = open(av[ac - 1], O_RDONLY);
	if (fd == -1)
		printf("error");
	char *str = get_next_line(fd);
	int i = 0;
	while (str && i++ < 5)
	{
		printf("line = %s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}
