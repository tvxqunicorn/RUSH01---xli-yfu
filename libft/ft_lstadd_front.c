/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:25:19 by xli               #+#    #+#             */
/*   Updated: 2021/03/05 11:19:36 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	new->next = *lst;
	*lst = new;
	return (1);
}
