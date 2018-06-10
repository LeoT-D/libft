/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:55:05 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/10 04:56:05 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			pf_expand_arg(va_list args, char *fmt)
{
	args = 0;
	fmt = 0;
	return (1);
}

int			pf_scan_format(va_list args, char *fmt)
{
	int			i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == CONV_CHAR)
		{
			pf_append_substr_to_buf(fmt, i);
			fmt += i + pf_expand_arg(args, fmt + i);
			i = 0;
		}
		else
		{
			i++;
		}
	}
	pf_append_substr_to_buf(fmt, i);
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list			args;
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
		pf_append_to_buf("[ :D ] ");
//		pf_append_to_buf(fmt);
		pf_scan_format(args, (char *)fmt);
		ft_putstr(g_pf_buf);
		free(g_pf_buf);
	}

	va_end(args);
	return (bytes);
}
