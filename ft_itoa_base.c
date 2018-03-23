/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:48:08 by ltanenba          #+#    #+#             */
/*   Updated: 2018/02/23 00:12:04 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(int n, int base)
{
	char	cipher[16];
	int		i;
	int		tmp;
	char	*res;

	ft_strcpy(cipher, "0123456789ABCDEF");
	if (base == 10)
		return (ft_itoa(n));
	i = -1;
	tmp = 0;
	res = ft_strnew(33);
	if (!res)
		return (0);
	if (!n)
		res[0] = '0';
	while (n)
	{
		tmp = n % base;
		n /= base;
		res[++i] = cipher[tmp];
	}
	ft_strrev(res);
	return (res);
}
