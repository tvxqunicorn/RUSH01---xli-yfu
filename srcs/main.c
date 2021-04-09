/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/09 23:03:34 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

void	solve(int n, int **map, int target[3])
{
	int	dp[n][n];
	int	ct[2];

	ct[0] = -1;
	target[2] = 0;
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
		{
			if (map[ct[0]][ct[1]] == map[ct[0] - 1][ct[1]] && map[ct[0]][ct[1]] == map[ct[0]][ct[1] - 1] && map[ct[0]][ct[1]] == map[ct[0] - 1][ct[1] - 1])
				dp[ct[0]][ct[1]] = ft_min(dp[ct[0]][ct[1] - 1], ft_min(dp[ct[0] - 1][ct[1]], dp[ct[0] - 1][ct[1] - 1])) + 1;
			else
				dp[ct[0]][ct[1]] = 1;
			if (dp[ct[0]][ct[1]] > target[2]) // didn't consider when there are multiple answers
			{
				target[2] = dp[ct[0]][ct[1]];
				target[0] = ct[0];
				target[1] = ct[1];
			}
		}
	}
}

int	main(void)
{
	int		n;
	char	c;
	int		**map;
	int		ct[3];
	parse(&n, &c, &map);
	if (n <= 0)
	{
		ft_putendl_fd("", 1);
		return (0);
	}
	solve(n, map, ct);// ct[0] : target i, ct[1] : target j, ct[2] : max_square_size
	print_ans(n, c, map, ct);
	ct[0] = -1;
	while (++ct[0] < n)
		free(map[ct[0]]);
	free(map);
}
