/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/11 21:28:17 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

void	sub_solve(int *dp, char *map, int target[2], int idx[4])
{
	int	ct[2];

	ct[0] = 0;
	while (++ct[0] < idx[2])
	{
		ct[1] = 0;
		while (++ct[1] < idx[2])
		{
			idx[0] = ct[0] * idx[2] + ct[1];
			idx[1] = ct[0] * idx[3] + ct[1];
			if (map[idx[1]] == map[idx[1] - 1]
				&& map[idx[1]] == map[idx[1] - idx[3]]
				&& map[idx[1]] == map[idx[1] - idx[3] - 1])
				dp[idx[0]] = 1 + ft_min(dp[idx[0] - 1],
						dp[idx[0] - idx[2]],
						dp[idx[0] - idx[2] - 1]);
			else
				dp[idx[0]] = 1;
			if (dp[idx[0]] > target[1])
			{
				target[1] = dp[idx[0]];
				target[0] = idx[1];
			}
		}
	}
}

void	solve(int n, char *map, int target[2])
{
	int	*dp;
	int	ct[2];
	int	idx[4];

	dp = malloc(n * n * sizeof(int));
	ct[0] = -1;
	while (++ct[0] < n)
	{
		dp[ct[0]] = 1;
		dp[ct[0] * n] = 1;
	}
	ct[0] = 0;
	idx[2] = n;
	idx[3] = n + 1;
	sub_solve(dp, map, target, idx);
	free(dp);
}

int	main(void)
{
	int		n;
	char	c[2];
	char	*map;
	int		ct[2];

	parse(&n, c, &map);
	ct[0] = 0;
	ct[1] = 1;
	solve(n, map, ct);
	print_ans(n, c[0], map, ct);
	free(map);
}
