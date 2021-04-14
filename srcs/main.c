/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/14 20:50:42 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

static inline void	parse(register unsigned int n, register unsigned char **map)
{
	register unsigned int	ct[2];
	register unsigned char	*t;

	ct[1] = n * (1 + n) - 1;
	map[0] = malloc(ct[1] + 1);
	t = map[0];
	while (ct[1] > 0)
	{
		ct[0] = read(0, t, ct[1]);
		t += ct[0];
		ct[1] -= ct[0];
	}
}

static inline void	print_ans(register unsigned int n[3],
register unsigned char c, register unsigned char *map,
register unsigned char *pos)
{
	register unsigned int	ct[2];
	register unsigned char	*t;

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

static inline void	sub_solve(register unsigned int *dp,
register unsigned char *map, register unsigned int n[3],
register unsigned char **pos)
{
	register unsigned int	ct[2];

	ct[0] = 0;
	while (++ct[0] < n[0] && ++dp && ++map && ++map)
	{
		ct[1] = 0;
		while (++ct[1] < n[0] && ++dp && ++map)
		{
			if (map[0] == *(map - 1) && map[0] == *(map - n[1])
				&& map[0] == *(map - 1 - n[1]))
			{
				dp[0] = 1 + *(dp - 1);
				if (dp[0] > 1 + *(dp - n[0]))
					dp[0] = 1 + *(dp - n[0]);
				if (dp[0] > 1 + *(dp - n[1]))
					dp[0] = 1 + *(dp - n[1]);
			}
			else
				dp[0] = 1;
			if (dp[0] == ++n[2])
				pos[0] = map;
			else
				--n[2];
		}
	}
}

static inline void	solve(register unsigned int n[3],
register unsigned char *map, register unsigned char **pos)
{
	register unsigned int	*dp;
	register unsigned int	*temp[2];

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
	sub_solve(dp + n[0] - 1, map + n[0] - 1, n, pos);
	free(dp);
}

int	main(void)
{
	unsigned int	n[3];
	unsigned char	c[2];
	unsigned char	*map;
	unsigned char	*pos;

	n[0] = 0;
	while (read(0, c, 1))
	{
		if (c[0] == '\n')
			break ;
		n[0] = 10 * n[0] + c[0] - '0';
	}
	read(0, c, 2);
	parse(n[0], &map);
	n[1] = n[0] + 1;
	n[2] = 1;
	pos = map;
	solve(n, map, &pos);
	print_ans(n, c[0], map, pos);
	free(map);
}
