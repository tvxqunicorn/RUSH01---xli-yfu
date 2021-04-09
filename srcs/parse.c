/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:41 by yfu               #+#    #+#             */
/*   Updated: 2021/04/09 23:04:07 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

void	parse(int *n, char *c, int ***map)
{
	char	*line;
	int		ct[2];

	get_next_line(0, &line);
	*n = ft_atoi(line); // what if no input ?
	free(line);
	get_next_line(0, &line);
	*c = *line;
	free(line);
	if (*n > 0)
	{
		*map = malloc(*n * sizeof(int*)); // what if malloc Fail ?
		ct[0] = -1;
		while (++ct[0] < *n)
			map[0][ct[0]] = malloc(*n * sizeof(int));
		ct[0] = -1;
		while (++ct[0] < *n)
		{
			ct[1] = -1;
			get_next_line(0, &line);
			while (++ct[1] < *n)
				map[0][ct[0]][ct[1]] = line[ct[1]] - '0';
			free(line);
		}
	}
	else
		*map = NULL;
}

void	print_ans(int n, char c, int **map, int target[3])
{
	int	ct[2];

	ct[0] = -1;
	while (++ct[0] < n)
	{
		ct[1] = -1;
		while (++ct[1] < n)
		{
			if (ct[0] > target[0] - target[2] && ct[0] <= target[0] && ct[1] > target[1] - target[2] && ct[1] <= target[1])
				ft_putchar_fd(c, 1);
			else
				ft_putnbr_fd(map[ct[0]][ct[1]], 1);
		}
		ft_putendl_fd("", 1);
	}
}
