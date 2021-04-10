/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:00:11 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 09:14:15 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t count, size_t size)
{
	return (ft_memory(count, size, NULL, push));
}

void	ft_free(void *del)
{
	ft_memory(0U, 0U, del, pop);
}

void	ft_free_all(void)
{
	ft_memory(0U, 0U, NULL, clear);
}
