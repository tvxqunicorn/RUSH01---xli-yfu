/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:08:54 by yfu               #+#    #+#             */
/*   Updated: 2021/04/10 09:56:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr2(char const *s, int start, int len)
{
	char	*ans;
	int		ct;

	ans = malloc((len + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ct = 0;
	while (ct < len && s[ct] != '\0')
	{
		ans[ct] = s[start + ct];
		ct++;
	}
	ans[ct] = '\0';
	return (ans);
}

int	ft_str_add(t_lst *dst, char *s, int len)
{
	t_str	*str;
	t_str	*temp;
	int		idx;

	str = malloc(1 * sizeof(t_str));
	if (len < 0 || !s || !str)
		return (-1);
	idx = -1;
	str->next = 0;
	str->s = malloc((len + 1) * sizeof(char));
	if (str->s == NULL)
		return (-1);
	while (++idx < len)
		str->s[idx] = s[idx];
	str->s[idx] = '\0';
	temp = dst->str;
	if (!temp)
	{
		dst->str = str;
		dst->len = len;
		return (1);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = str;
	dst->len += len;
	return (1);
}

t_lst	*ft_lst_add(t_lst **dst, int fd)
{
	t_lst	*temp;

	temp = malloc(1 * sizeof(t_lst));
	if (temp == NULL)
		return (NULL);
	temp->str = 0;
	temp->len = 0;
	temp->fd = fd;
	temp->idx = 0;
	temp->next = 0;
	if (*dst == 0)
		*dst = temp;
	else
	{
		temp->next = *dst;
		*dst = temp;
	}
	return (temp);
}

int	ft_clean_lst(t_lst *lst)
{
	t_str	*temp;

	lst->idx = 0;
	lst->len = 0;
	while (lst->str)
	{
		temp = lst->str;
		lst->str = lst->str->next;
		free(temp->s);
		free(temp);
	}
	lst->str = 0;
	return (0);
}

int	ft_del_lst(t_lst *target, t_lst **head, int *res)
{
	t_lst	*temp;

	if (res[1] != -1 && target->len)
		return (1);
	if (target == *head)
	{
		if (target->str)
			ft_clean_lst(target);
		if (target->next)
			*head = target->next;
		else
			*head = 0;
		free(target);
		return (res[1] == -1 ? -1 : (res[1] == 1 && res[0]));
	}
	temp = *head;
	while (temp->next != target)
		temp = temp->next;
	temp->next = target->next;
	if (target->str)
		ft_clean_lst(target);
	free(target);
	return (res[1] == -1 ? -1 : (res[1] == 1 && res[0]));
}
