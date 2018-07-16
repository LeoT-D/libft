/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 14:53:20 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/16 13:40:04 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks the set of arguments [ av ] for a dash followed by any
** number of option characters, as specified by the option string.
** 			[ -??? ]
** 			[ -?:? ] : Colon (':') is used in the option string to
** 					   indicate that an option requires an argument.
**
** [ g_opt_index ] : Tracks the string in av[] that ft_getopt last read from.
** [ g_opt_arg ]   : Points to an option argument if applicable.
** [ g_opt_reset ] : Init's to 0. Set to 1 to reset/free.
*/

int				g_opt_index = 1;
int				g_opt_optchar = 0;
char			*g_opt_arg = NULL;
int				g_opt_reset = 0;
char			*g_ostr_curr;
char			*g_av_curr;
int				g_opt_error;

static void		st_reset(int *i)
{
	*i = 1;
	g_opt_index = 1;
	g_opt_optchar = 0;
	g_opt_arg = NULL;
	g_opt_error = 0;
	g_opt_reset = 0;
}

static int		st_error(int errid)
{
	g_opt_error = errid;
	g_opt_reset = 1;
	return (errid);
}

static int		st_check_opt(char **av, int *i)
{
	if (g_ostr_curr[1] == ':')
	{
		if (g_av_curr[-1] != '-')
			return (st_error(-1));
		if (g_av_curr[1])
			g_opt_arg = ft_strsub(g_av_curr, 1, ft_strlen(g_av_curr + 1));
		else
		{
			g_opt_arg = ft_strdup(av[g_opt_index + 1]);
			if (g_opt_arg)
				g_opt_index += 1;
		}
		g_opt_index++;
		*i = 1;
	}
	else
	{
		*i += 1;
		if (av[g_opt_index][*i] == '\0')
		{
			*i = 1;
			g_opt_index++;
		}
	}
	return ((int)(*g_ostr_curr));
}

int				ft_getopt(int ac, char **av, const char *opt_string)
{
	static int		i = 1;

	if (g_opt_reset)
		st_reset(&i);
	while (g_opt_index < ac)
	{
		if (av[g_opt_index][0] == '-')
		{
			g_ostr_curr = ft_strchr(opt_string, av[g_opt_index][i]);
			if (g_ostr_curr && *g_ostr_curr)
			{
				g_av_curr = (char *)av[g_opt_index] + i;
				return (st_check_opt((char **)av, &i));
			}
			return (st_error(-1));
		}
		else
			return (st_error(-1));
	}
	return (st_error(-1));
}
