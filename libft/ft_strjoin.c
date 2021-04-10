/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:52:45 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 15:11:11 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1 || !s2 || i < 0 || str == NULL)
		return (NULL);
	j = -1;
	while (++j < len)
	{
		if (j < i)
			str[j] = s1[j];
		else
			str[j] = s2[j - i];
	}
	str[i] = '\0';
	return (str);
}
