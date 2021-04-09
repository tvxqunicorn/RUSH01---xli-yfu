/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_bound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:31:34 by yfu               #+#    #+#             */
/*   Updated: 2021/04/06 20:37:38 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	upper_bound(int *arr, int arr_size, int target)
{
	int	lb;
	int	ub;
	int	mid;

	lb = -1;
	ub = arr_size;
	while (ub - lb > 1)
	{
		mid = (ub + lb) / 2;
		if (arr[mid] > target)
			ub = mid;
		else
			lb = mid;
	}
	return (ub);
}
