/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:41 by yfu               #+#    #+#             */
/*   Updated: 2021/04/11 16:47:22 by yfu              ###   ########lyon.fr   */
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
		read(0, &c, 1);
		if (c == '\n')
			return (ans);
		ans = 10 * ans + c - '0';
	}
	return (ans);
}

void	parse(int *n, char *c, char ***map)
{
	int		ct;
	char	a;
	char	*t;

	*n = read_int();
	read(0, c, 1);
	read(0, &a, 1);
	*map = malloc(*n * sizeof(char *));
	**map = malloc(*n * (*n + 1) * sizeof(char));
	t = map[0][0];
	ct = read(0, t, *n * (*n + 1));
	while (ct > 0)
	{
		t += ct;
		ct = read(0, t, *n * (*n + 1));
	}
	t = map[0][0] + 1 + *n;
	ct = 0;
	while (++ct < *n)
	{
		map[0][ct] = t;
		t += 1 + *n;
	}
}

void	print_ans(int n, char c, char **map, int target[3])
{
	int		ct[2];
	char	*t;

	ct[0] = target[0] - target[2];
	while (++ct[0] <= target[0])
	{
		ct[1] = target[1] - target[2];
		while (++ct[1] <= target[1])
			map[ct[0]][ct[1]] = c;
	}
	ct[0] = n * (n + 1) - 1;
	t = map[0];
	while (ct[0] > 0)
	{
		ct[1] = write(1, t, ct[0]);
		t += ct[1];
		ct[0] -= ct[1];
	}
	write(1, "\n", 1);
}
