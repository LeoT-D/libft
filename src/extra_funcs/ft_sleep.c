/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 14:03:57 by ltanenba          #+#    #+#             */
/*   Updated: 2018/07/15 14:47:14 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

/*
** Takes as a parameter a number of seconds to suspend a thread.
** Returns [ 0 ] on success.
** 		   [ N ] the number of seconds unslept on any interrupt.
*/

unsigned int			ft_sleep(unsigned int seconds)
{
	struct timespec			time_to_sleep;
	struct timespec			time_unslept;
	int						err;

	time_to_sleep.tv_nsec = 0;
	time_to_sleep.tv_sec = seconds;
	err = nanosleep(&time_to_sleep, &time_unslept);
	if (err != 0)
		return (time_unslept.tv_nsec > 5e8 ?
				time_unslept.tv_sec + 1 : time_unslept.tv_sec);
	else
		return (0);
}
