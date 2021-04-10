/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:52:45 by xli               #+#    #+#             */
/*   Updated: 2021/04/10 11:52:17 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		l2;
	int		ct;
	char	*str;

	l2 = ft_strlen(s1);
	l = ft_strlen(s1) + ft_strlen(s2);
	str = ft_memory(l + 1, sizeof(char), 0, push);
	if (!s1 || !s2 || l < 0 || !str)
		return (NULL);
	ct = -1;
	while (++ct < l)
	{
		if (ct < l2)
			str[ct] = s1[ct];
		else
			str[ct] = s2[ct - l2];
	}
	str[l] = '\0';
	return (str);
}
