/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:03:58 by ltanenba          #+#    #+#             */
/*   Updated: 2018/04/26 16:48:19 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_dafuq(t_conv *conv)
{
	conv->done = 1;
	pf_exit(2);
}

void		pf_escpercent(t_conv *conv)
{
	pf_buffer("%", 1);
	*(conv->fmt_ptr) = *(conv->fmt_ptr) + 1;
	conv->done = 1;
}
