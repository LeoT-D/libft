/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 04:57:23 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/08 07:53:11 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int				cursor_move(t_prompt *p, long c)
{
	if (c == LEFT_ARR)
		if (p->pos > 0)
        	p->pos--;
	if (c == RIGHT_ARR)
		if (p->pos != p->len)
        	p->pos++;
	if (c == UP_ARR)
		p->pos = 0;
	if (c == DOWN_ARR)
		p->pos = p->len;
	print_line(p);
	return (0);
}
