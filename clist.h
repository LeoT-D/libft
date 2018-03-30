/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 03:53:17 by ltanenba          #+#    #+#             */
/*   Updated: 2018/03/30 01:11:46 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIST_H
# define CLIST_H

typedef struct			s_clist
{
	struct s_clist		*left;
	struct s_clist		*right;
	struct s_clist		*up;
	struct s_clist		*down;
	struct s_clist		*head;
	char				*id;
	size_t				content_size;
	void				*content;
}						t_clist;

t_clist					*ft_lstcnew(void *content, size_t content_size, char *id);
void					ft_delinkud(t_clist *n);
void					ft_delinklr(t_clist *n);
void					ft_relinkud(t_clist *n);
void					ft_relinklr(t_clist *n);
void					ft_lstcaddl(t_clist *lst, t_clist *n);
void					ft_lstcaddr(t_clist *lst, t_clist *n);
void					ft_lstcaddu(t_clist *lst, t_clist *n);
void					ft_lstcaddd(t_clist *lst, t_clist *n);

#endif
