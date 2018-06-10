/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:55:05 by ltanenba          #+#    #+#             */
/*   Updated: 2018/04/26 16:57:59 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "tables.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void		pf_exit(int id)
{
	if (id == 1)
		ft_putstr("ft_printf: \033[38;5;1;5m\033[1mMalloc failure!\n\033[m");
	else if (id == 2)
		ft_putstr("ft_printf: \033[38;5;1;5m\033[1mBad syntax!\n\033[m");
	exit(0);
}

char		*pf_buffer(char *str, int len)
{
	static char		*buffer;
	char			*tmp;

	if (len == -1)
		buffer = ft_strnew(1);
	if (len > 0)
	{
		PF_MALL_CHECK(tmp = ft_strsub(str, 0, len));
		PF_MALL_CHECK(ft_strjoin_free(&buffer, tmp));
		free(tmp);
	}
	return (buffer);
}

int			pf_print(void)
{
	char			*tmp;
	int				len;

	tmp = pf_buffer("", 0);
	len = (int)ft_strlen(tmp);
	write(1, tmp, len);
	return (len);
}

t_conv		*pf_initconv(char **fmt_ptr, t_pfarg arg)
{
	t_conv			*tmp;

	PF_MALL_CHECK(tmp = (t_conv *)malloc(sizeof(t_conv)));
	tmp->fmt_ptr = fmt_ptr;
	tmp->arg = arg;
	tmp->width = 0;
	tmp->precision = 0;
	tmp->hhll = 0;
	tmp->done = 0;
	return (tmp);
}

int			ft_printf(const char *fmt, ...)
{
	int				i;
	va_list			args;
	t_pfarg			arg;
	t_conv			*conv;

	va_start(args, fmt);
	i = -1;
	pf_buffer("", -1);
	while (*(fmt + ++i))
		if (fmt[i] == CONV_CHAR)
		{
			pf_buffer((char *)fmt, i);
			fmt += i;
			i = -1;
			arg = va_arg(args, t_pfarg);
			conv = pf_initconv((char **)&fmt, arg);
			pf_parse(conv);
			free(conv);
		}
	pf_buffer((char *)fmt, i);
	va_end(args);
	return (pf_print());
}
