/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:33:26 by ltanenba          #+#    #+#             */
/*   Updated: 2018/02/23 00:05:03 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	int		is_neg;

	i = -1;
	is_neg = 0;
	res = ft_strnew(12);
	if (!res)
		return (0);
	if (!n)
		res[0] = '0';
	if (n < 0 && (is_neg = 1))
		n *= -1;
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	while (n)
	{
		*(res + ++i) = (n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		*(res + ++i) = '-';
	ft_strrev(res);
	return (res);
}
