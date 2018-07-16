/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:48:37 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/16 13:48:58 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsep(char **str, char *delim)
{
	char	*tmp;

	if (!str || !*str || !**str)
		return (NULL);
	tmp = *str;
	while (**str)
	{
		if (ft_strchr(delim, **str) != NULL)
		{
			**str = '\0';
			*str += 1;
			break ;
		}
		*str += 1;
	}
	return (tmp);
}
