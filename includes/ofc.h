/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:56:47 by yfu               #+#    #+#             */
/*   Updated: 2021/04/12 23:02:32 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFC_H
# define OFC_H
# include <unistd.h>
# include <stdlib.h>

void			parse(unsigned int *n, unsigned char *c, unsigned char **map);
void			print_ans(unsigned int n, unsigned char c,
					unsigned char *m, unsigned int t[2]);
unsigned int	ft_min(unsigned int a, unsigned int b, unsigned int c);

#endif
