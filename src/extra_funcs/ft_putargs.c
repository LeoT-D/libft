/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:25:11 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/16 15:43:53 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putargs_fd_delim(char **av, int fd, char delim)
{
	int			i;

	i = -1;
	if (!av || !*av)
		return ;
	ft_putstr_fd(av[++i], fd);
	while (av[++i] != NULL)
	{
		ft_putchar_fd(delim, fd);
		ft_putstr_fd(av[i], fd);
	}
}

void		ft_putargs_fd(char **av, int fd)
{
	ft_putargs_fd_delim(av, fd, ' ');
}

void		ft_putargs_delim(char **av, char delim)
{
	ft_putargs_fd_delim(av, STDOUT_FILENO, delim);
}

void		ft_putargs(char **av)
{
	ft_putargs_fd_delim(av, STDOUT_FILENO, ' ');
}
