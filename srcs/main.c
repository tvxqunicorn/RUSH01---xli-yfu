/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/09 22:04:59 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"

int	main(void)
{
	int		n;
	char	c;
	int		**map;
	parse(&n, &c, &map);
	
}

/*
int	main()
{
	int n; // deal with n == 0 ? n < 0 ?
	scanf("%d\n", &n);
	char	c;
	scanf("%c\n", &c);
	int map[n][n], dp[n][n], max_square = 0, target_i = -1, target_j = -1;
	for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < n ; ++j)
	{
		char	temp;
		scanf(" %c", &temp);
		map[i][j] = temp - '0';
	}
	for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < n ; ++j) dp[i][j] = 1;
	for(int i = 1 ; i < n ; ++i) for(int j = 1 ; j < n ; ++j)
	{
		if (map[i][j] == map[i][j - 1] && map[i][j] == map[i - 1][j] && map[i][j] == map[i - 1][j - 1])
			dp[i][j] = MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
		if (dp[i][j] > max_square || target_i == -1 || (dp[i][j] == max_square && map[i][j] < map[target_i][target_j]))
		{
			max_square = dp[i][j];
			target_i = i;
			target_j = j;
		}
	}
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
			if (i > target_i - max_square && i <= target_i && j > target_j - max_square && j <= target_j)
				printf("%c", c);
			else
				printf("%d", map[i][j]);
		}
		printf("\n");
	}
}
*/