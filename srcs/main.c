/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/10 15:23:00 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

void	sub_solve(int ct[2], int **dp, char **map, int target[3])
{
	if (map[ct[0]][ct[1]] == map[ct[0] - 1][ct[1]]
		&& map[ct[0]][ct[1]] == map[ct[0]][ct[1] - 1]
		&& map[ct[0]][ct[1]] == map[ct[0] - 1][ct[1] - 1])
		dp[ct[0]][ct[1]] = 1 + ft_min(dp[ct[0]][ct[1] - 1], ft_min(
					dp[ct[0] - 1][ct[1]], dp[ct[0] - 1][ct[1] - 1]));
	else
		dp[ct[0]][ct[1]] = 1;
	if (dp[ct[0]][ct[1]] > target[2])
	{
		target[2] = dp[ct[0]][ct[1]];
		target[0] = ct[0];
		target[1] = ct[1];
	}
}

void	solve(int n, char **map, int target[3])
{
	int	**dp;
	int	ct[2];

	dp = malloc(n * sizeof(int *));
	ct[0] = -1;
	while (++ct[0] < n)
		dp[ct[0]] = malloc(n * sizeof(int));
	ct[0] = -1;
	while (++ct[0] < n)
	{
		dp[0][ct[0]] = 1;
		dp[ct[0]][0] = 1;
	}
	ct[0] = 0;
	while (++ct[0] < n)
	{
		ct[1] = 0;
		while (++ct[1] < n)
			sub_solve(ct, dp, map, target);
	}
	ct[0] = -1;
	while (++ct[0] < n)
		free(dp[ct[0]]);
	free(dp);
}

int	main(void)
{
	int		n;
	char	c;
	char	**map;
	int		ct[3];

	parse(&n, &c, &map);
	if (n <= 0)
	{
		ft_putendl_fd("", 1);
		return (0);
	}
	ct[0] = 0;
	ct[1] = 0;
	ct[2] = 1;
	solve(n, map, ct);
	print_ans(n, c, map, ct);
	ct[0] = -1;
	while (++ct[0] < n)
		free(map[ct[0]]);
	free(map);
}
