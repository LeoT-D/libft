/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:38:31 by ltanenba          #+#    #+#             */
/*   Updated: 2018/02/23 00:08:29 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strrev(char *str)
{
	char	*tmp;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	tmp = ft_strnew(len + 1);
	while (*(str + ++i))
		*(tmp + (len - i - 1)) = *(str + i);
	*(tmp + i) = '\0';
	i = -1;
	while (*(tmp + ++i))
		*(str + i) = *(tmp + i);
	ft_strdel(&tmp);
}
