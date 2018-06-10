/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 02:28:39 by ltanenba          #+#    #+#             */
/*   Updated: 2018/06/10 04:50:50 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				pf_append_substr_to_buf(const char *str, size_t len)
{
	char		*old_buf;

	if (len == 0)
		return (0);
	old_buf = g_pf_buf;
	PF_MALLCHECK(g_pf_buf = ft_strnew(ft_strlen(g_pf_buf) + len));
	ft_strcpy(g_pf_buf, old_buf);
	ft_strncat(g_pf_buf, str, len);
	free(old_buf);
	return (0);
}

int				pf_append_to_buf(const char *str)
{
	return (pf_append_substr_to_buf(str, ft_strlen(str)));
}
