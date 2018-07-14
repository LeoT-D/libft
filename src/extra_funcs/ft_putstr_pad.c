/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:42:21 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/13 18:51:51 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints _str_ to _fd_ padded with a number of _char c_
** to the left or right of _str_ to fill space up to the _max_ len.
**
** Returns the length of the printed string.
*/

size_t			ft_putstr_padl(int max, char *str, int fd, char c)
{
	int			strlen;
	char		buf[4096];
	int			i;

	i = -1;
	if (max > 4095)
		max = 4095;
	ft_bzero(buf, 256);
	strlen = ft_strlen(str);
	while (++i < max - strlen)
		buf[i] = c;
	strncat(buf, str, max + 1);
	ft_putstr_fd(buf, fd);
	return (ft_strlen(buf));
}

size_t			ft_putstr_padr(int max, char *str, int fd, char c)
{
	int			strlen;
	char		buf[4096];
	int			i;

	i = -1;
	if (max > 4095)
		max = 4095;
	ft_bzero(buf, 256);
	strlen = ft_strlen(str);
	strncpy(buf, str, strlen);
	i += strlen;
	while (++i < max)
		buf[i] = c;
	ft_putstr_fd(buf, fd);
	return (ft_strlen(buf));
}
