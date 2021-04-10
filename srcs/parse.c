/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:41 by yfu               #+#    #+#             */
/*   Updated: 2021/04/10 14:20:11 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

int	read_int(void)
{
	int		ans;
	char	c;

	ans = 0;
	while (1)
	{
		if (read(0, &c, 1) != 1)
			return (ans);
		if (c == '\n')
			return (ans);
		ans = 10 * ans + c - '0';
	}
	return (ans);
}

void	get_line(int n, char *line)
{
	while (1)
	{
		if (read(0, line, 1) != 1)
			return ;
		if (line[0] != '\n')
			break ;
	}
	if (n > 1)
		read(0, line + 1, n - 1);
}

void	parse(int *n, char *c, char ***map)
{
	int		ct[2];

	*n = read_int();
	if (*n <= 0)
		return ;
	read(0, c, 1);
	*map = malloc(*n * sizeof(char *));
	ct[0] = -1;
	while (++ct[0] < *n)
		map[0][ct[0]] = malloc(*n * sizeof(char));
	ct[0] = -1;
	while (++ct[0] < *n)
		get_line(*n, map[0][ct[0]]);
}

void	print_ans(int n, char c, char **map, int target[3])
{
	int	ct[2];

	ct[0] = -1;
	while (++ct[0] < n)
	{
		ct[1] = -1;
		while (++ct[1] < n)
		{
			if (ct[0] > target[0] - target[2] && ct[0] <= target[0]
				&& ct[1] > target[1] - target[2] && ct[1] <= target[1])
				ft_putchar_fd(c, 1);
			else
				ft_putchar_fd(map[ct[0]][ct[1]], 1);
		}
		ft_putendl_fd("", 1);
	}
}
