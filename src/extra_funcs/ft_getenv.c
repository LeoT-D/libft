/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 01:31:22 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/13 18:36:22 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_getenv(const char *name)
{
	char		*val;
	int			len;
	int			i;

	i = 0;
	while (g_environ[i])
	{
		val = ft_strchr(g_environ[i], '=');
		len = ft_strlen(name);
		if (!ft_strncmp(g_environ[i], name, len) && g_environ[i][len] == '=')
			return (val + 1);
		i++;
	}
	return (0);
}
