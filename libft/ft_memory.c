/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:04:02 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 14:21:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_2(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

static	void	ft_lstdelone_2(t_list **head, t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (!head || !lst)
		return ;
	temp = *head;
	if (temp == lst)
		*head = temp->next;
	else
	{
		while (temp && temp->next != lst)
			temp = temp->next;
		if (!temp)
			return ;
		temp->next = lst->next;
	}
	if (del)
		del(lst->content);
	free(lst);
}

static	void	*ft_calloc_2(size_t count, size_t size)
{
	void	*dst;

	dst = malloc(count * size);
	if (dst == NULL)
		return (NULL);
	ft_memset(dst, 0, count * size);
	return (dst);
}

static	void	ft_lstclear_2(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		ft_lstdelone(temp, del);
		temp = next;
	}
	*lst = NULL;
}

void	*ft_memory(size_t count, size_t size, void *del, t_memory type)
{
	static t_list	*head;
	void			*new_mem;

	if (type == push)
	{
		new_mem = ft_calloc_2(count, size);
		if (new_mem == NULL)
			ft_putstr_fd("ERROR_IN_FT_MEMORY_0\n", 1);
		else if (!(ft_lstadd_front(&head, ft_lstnew_2(new_mem))))
			ft_putstr_fd("ERROR_IN_FT_MEMORY_1\n", 1);
		return (new_mem);
	}
	if (type == pop)
		ft_lstdelone_2(&head, ft_lstfind(head, del), free);
	else
		ft_lstclear_2(&head, free);
	return (NULL);
}
