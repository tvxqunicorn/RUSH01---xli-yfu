/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:55:29 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 14:39:08 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nb_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -1 * n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = ft_nb_len(nb);
	str = ft_malloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -1 * nb;
	}
	while (nb > 0)
	{
		str[len] = '0' + (nb % 10);
		nb = nb / 10;
		len--;
	}
	return (str);
}
