/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:57:41 by yfu               #+#    #+#             */
/*   Updated: 2021/04/13 12:18:53 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

void	parse(unsigned int *n, unsigned char *c, unsigned char **map)
{
	unsigned int	ct[2];
	unsigned char	*t;

	*n = 0;
	while (read(0, c, 1))
	{
		if (*c == '\n')
			break ;
		*n = 10 * *n + *c - '0';
	}
	read(0, c, 2);
	ct[1] = *n * (1 + *n) - 1;
	*map = malloc(ct[1] + 1);
	t = map[0];
	while (ct[1] > 0)
	{
		ct[0] = read(0, t, ct[1]);
		t += ct[0];
		ct[1] -= ct[0];
	}
}

void	print_ans(unsigned int n[3], unsigned char c,
unsigned char *map, unsigned char *pos)
{
	unsigned int	ct[2];
	unsigned char	*t;

	ct[0] = 0;
	t = pos + 1;
	while (ct[0] < n[2])
	{
		ct[1] = 0;
		while (ct[1] < n[2])
		{
			*(--t) = c;
			++ct[1];
		}
		t -= n[1] - n[2];
		++ct[0];
	}
	ct[0] = n[0] * n[1] - 1;
	t = map;
	while (ct[0] > 0)
	{
		ct[1] = write(1, t, ct[0]);
		t += ct[1];
		ct[0] -= ct[1];
	}
	write(1, "\n", 1);
}
