/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 01:31:22 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/12 02:20:23 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern char		**environ;

char		*ft_getenv(const char *name)
{
	char		*val;
	int			len;
	int			i;

	i = 0;
	while (environ[i])
	{
		val = ft_strchr(environ[i], '=');
		len = ft_strlen(name);
		if (!ft_strncmp(environ[i], name, len) && environ[i][len] == '=')
			return (val + 1);
		i++;
	}
	return (0);
}
