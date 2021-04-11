/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:56:47 by yfu               #+#    #+#             */
/*   Updated: 2021/04/10 14:10:55 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFC_H
# define OFC_H
# include <unistd.h>
# include <stdlib.h>

void	parse(int *n, char *c, char ***map);
void	solve(int n, char **map, int target[3]);
void	print_ans(int n, char c, char **map, int target[3]);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

#endif
