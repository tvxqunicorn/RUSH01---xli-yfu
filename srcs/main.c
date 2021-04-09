/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:59:29 by yfu               #+#    #+#             */
/*   Updated: 2021/04/09 22:38:49 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ofc.h"
#include <stdio.h>

int	main(void)
{
	int		n;
	char	c;
	int		**map;
	parse(&n, &c, &map);
	printf("%d %c\n", n, c);
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j) printf("%d ", map[i][j]);
		printf("\n");
	}
	for(int i = 0 ; i < n ; ++i) free(map[i]);
	free(map);
}
