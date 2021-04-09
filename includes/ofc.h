/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:56:47 by yfu               #+#    #+#             */
/*   Updated: 2021/04/09 23:03:46 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFC_H
# define OFC_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

void	parse(int *n, char *c, int ***map);
void	solve(int n, int **map, int target[3]);
void	print_ans(int n, char c, int **map, int target[3]);

#endif