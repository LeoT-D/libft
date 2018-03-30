/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_relink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 04:04:06 by ltanenba          #+#    #+#             */
/*   Updated: 2018/03/16 07:25:52 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_relinklr(t_clist *n)
{
	(n->left)->right = n;
	(n->right)->left = n;
}

void	ft_relinkud(t_clist *n)
{
	(n->up)->down = n;
	(n->down)->up = n;
}
