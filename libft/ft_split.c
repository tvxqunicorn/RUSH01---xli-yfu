/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:19:35 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 14:40:18 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_nb_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_str;

	if (!s[0])
		return (0);
	i = 0;
	nb_str = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		nb_str++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb_str);
}

static	void	ft_next_str(char **next_str, unsigned int *next_str_len,
						char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while (*(*next_str + i))
	{
		if (*(*next_str + i) == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

static	char	**ft_freeee(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_str = ft_nb_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_str + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i++ < nb_str)
	{
		ft_next_str(&next_str, &next_str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (tab[i] == NULL)
			return (ft_freeee(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
