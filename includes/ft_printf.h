/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:33:29 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/10 02:58:04 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define CONV_CHAR '%'
# define PF_MALLCHECK(x) if (!(x)) return (-1)
# define PF_ERRCHECK(x) if ((x) == -1) return (-1)

char						*g_pf_buf;

enum						e_size_mod
{
	HH_TYPE = 1,
	H_TYPE = 2,
	L_TYPE = 4,
	LL_TYPE = 8
};

typedef struct				s_conv
{
	char					conv;
	unsigned char			hhll;
//	int						width;
//	int						precision;
}							t_conv;

int							ft_printf(const char *format, ...);
int							pf_append_to_buf(char *str);
int							pf_append_substr_to_buf(char *str, size_t len);

#endif
