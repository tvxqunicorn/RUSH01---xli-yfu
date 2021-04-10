/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:52:12 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 14:54:27 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (!ss1 || !ss2)
		return (0);
	if (n == 0)
		return (0);
	if (*ss1 == 0 || *ss2 == 0 || *ss1 != *ss2)
		return (*ss1 - *ss2);
	ss1++;
	ss2++;
	return (ft_strncmp((char *)(ss1), (char *)(ss2), n - 1));
}
