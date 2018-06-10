/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:52:30 by ltanenba          #+#    #+#             */
/*   Updated: 2018/04/26 16:47:46 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tables.h"
#include "libft.h"

static t_funk		st_get_op(t_conv *conv, t_funk *op_table)
{
	int			opid;

	opid = g_jump_table[**(conv->fmt_ptr) - ' '];
	return (op_table[opid]);
}

void				pf_parse(t_conv *conv)
{
	t_funk		funk;

	*(conv->fmt_ptr) = *(conv->fmt_ptr) + 1;
	funk = st_get_op(conv, g_ops_step0);
	funk(conv);
	if (conv->done)
		return ;
	pf_exit(2);
}
