/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:41 by yfu               #+#    #+#             */
/*   Updated: 2021/04/12 23:21:12 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

unsigned int	read_int(void)
{
	unsigned int	ans;
	unsigned char	c;

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

void	parse(unsigned int *n, unsigned char *c, unsigned char **map)
{
	unsigned int	ct[2];
	unsigned char	*t;

	*n = read_int();
	read(0, c, 2);
	*map = malloc(*n * (1 + *n) * sizeof(unsigned char));
	t = map[0];
	ct[1] = *n * (1 + *n) - 1;
	while (ct[1] > 0)
	{
		ct[0] = read(0, t, ct[1]);
		t += ct[0];
		ct[1] -= ct[0];
	}
}

void	print_ans(unsigned int n, unsigned char c,
unsigned char *map, unsigned int target[2])
{
	unsigned int	ct[2];
	unsigned char	*t;

	ct[0] = -1;
	t = map + target[0] + 1;
	while (++ct[0] < target[1])
	{
		ct[1] = -1;
		while (++ct[1] < target[1])
			*(--t) = c;
		t -= n + 1 - target[1];
	}
	ct[0] = n * (n + 1) - 1;
	t = map;
	while (ct[0] > 0)
	{
		ct[1] = write(1, t, ct[0]);
		t += ct[1];
		ct[0] -= ct[1];
	}
	write(1, "\n", 1);
}
