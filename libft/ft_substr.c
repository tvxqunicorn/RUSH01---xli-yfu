/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:55:39 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 15:07:11 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (ft_strlen(s) <= start)
	{
		str = (char *)ft_malloc(1, sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = (size_t)ft_min((int)ft_strlen(s) - start, (int)len);
	str = ft_malloc(i, sizeof(char));
	if (!s || str == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = s[start + j];
	str[j] = '\0';
	return (str);
}
