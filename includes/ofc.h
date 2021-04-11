/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:56:47 by yfu               #+#    #+#             */
/*   Updated: 2021/04/11 21:14:29 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFC_H
# define OFC_H
# include <unistd.h>
# include <stdlib.h>

void	parse(int *n, char *c, char **map);
void	print_ans(int n, char c, char *map, int target[2]);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

#endif
