/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:55:05 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/10 02:57:36 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(const char *fmt, ...)
{
	va_list			args;
	t_conv			*conv;
	int				bytes;

	bytes = 0;
	va_start(args, fmt);

	if (ft_strchr(fmt, CONV_CHAR) == NULL)
	{
		ft_putstr(fmt);
		bytes = (int)ft_strlen(fmt);
	}
	else
	{
		PF_MALLCHECK(g_pf_buf = ft_strnew(0));
		//Do the thing.
		free(g_pf_buf);
	}

	va_end(args);
	return (bytes); //return (pf_print_buffer());
}
