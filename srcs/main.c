/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/13 00:48:15 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

void	sub_solve(unsigned int *dp, unsigned char *map,
unsigned int target[2], unsigned int idx[2])
{
	unsigned int	ct[2];

	ct[0] = 0;
	while (++ct[0] < idx[0])
	{
		ct[1] = 0;
		while (++ct[1] < idx[0])
		{
			if (*map == *(map - 1) && *map == *(map - idx[1])
				&& *map == *(map - 1 - idx[1]))
				*dp = 1 + ft_min(*(dp - 1), *(dp - idx[0]), *(dp - idx[0] - 1));
			else
				*dp = 1;
			if (*dp > target[1])
			{
				target[1] = *dp;
				target[0] = ct[0] * idx[1] + ct[1];
			}
			++dp;
			++map;
		}
		++dp;
		map += 2;
	}
}

void	solve(unsigned int n, unsigned char *map, unsigned int target[2])
{
	unsigned int	*dp;
	unsigned int	*temp[2];
	unsigned int	idx[2];

	dp = malloc(n * n * sizeof(unsigned int));
	temp[0] = dp;
	temp[1] = dp;
	idx[0] = n;
	idx[1] = n + 1;
	while (n-- > 0)
	{
		*temp[0] = 1;
		++temp[0];
		*temp[1] = 1;
		temp[1] += idx[0];
	}
	sub_solve(dp + idx[0] + 1, map + idx[1] + 1, target, idx);
	free(dp);
}

int	main(void)
{
	unsigned int	n;
	unsigned char	c[2];
	unsigned char	*map;
	unsigned int	ct[2];

	parse(&n, c, &map);
	ct[0] = 0;
	ct[1] = 1;
	solve(n, map, ct);
	print_ans(n, c[0], map, ct);
	free(map);
}
