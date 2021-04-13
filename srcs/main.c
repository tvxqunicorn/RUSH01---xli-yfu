/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/13 12:18:31 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

void	sub_solve(unsigned int *dp, unsigned char *map,
unsigned int n[3], unsigned char **pos)
{
	unsigned int	ct[2];

	ct[0] = 0;
	while (++ct[0] < n[0])
	{
		ct[1] = 0;
		while (++ct[1] < n[0])
		{
			if (*map == *(map - 1) && *map == *(map - n[1])
				&& *map == *(map - 1 - n[1]))
				*dp = 1 + ft_min(*(dp - 1), *(dp - n[0]), *(dp - n[1]));
			else
				*dp = 1;
			if (*dp > n[2])
			{
				n[2] = *dp;
				*pos = map;
			}
			++dp;
			++map;
		}
		++dp;
		map += 2;
	}
}

void	solve(unsigned int n[3], unsigned char *map, unsigned char **pos)
{
	unsigned int	*dp;
	unsigned int	*temp[2];

	dp = malloc(n[0] * n[0] * 4);
	temp[0] = dp;
	temp[1] = dp;
	while (--n[1] > 0)
	{
		*temp[0] = 1;
		++temp[0];
		*temp[1] = 1;
		temp[1] += n[0];
	}
	n[1] = n[0] + 1;
	sub_solve(dp + n[1], map + n[1] + 1, n, pos);
	free(dp);
}

int	main(void)
{
	unsigned int	n[3];
	unsigned char	c[2];
	unsigned char	*map;
	unsigned char	*pos;

	parse(n, c, &map);
	n[1] = n[0] + 1;
	n[2] = 1;
	pos = map;
	solve(n, map, &pos);
	print_ans(n, c[0], map, pos);
	free(map);
}
