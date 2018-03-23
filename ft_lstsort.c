/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:29:24 by ltanenba          #+#    #+#             */
/*   Updated: 2018/02/27 21:32:24 by ltanenba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		st_split(t_list *head, t_list **a, t_list **b)
{
	/* Trying out the fast/slow method */
	t_list	*fast;
	t_list	*slow;

	if (head == NULL || head->next == NULL)
	{
		*a = head;
		*b = NULL;
		return ;
	}
	slow = head;
	fast = head->next;
	/* fast moves forward by two, slow by one. Results in slow being at midpoint when fast reaches null */
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	/* split based on slow's position in the list */
	*a = head;
	*b = slow->next;
	/* delink two halves */
	slow->next = NULL;
}

static t_list	*st_merge(t_list *a, t_list *b, int (*cmp)(void *, void *))
{
	t_list	*result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	/* Pick either a or b based on cmp function, and recur 
	** cmp function return 1 if a is desired, 0 if b is desired */
	if (cmp(a->content, b->content))
	{
		result = a;
		result->next = st_merge(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = st_merge(a, b->next, cmp);
	}
	return(result);
}

void			ft_lstsort(t_list **head, int (*cmp)(void *, void *))
{
	t_list	*a;
	t_list	*b;
	t_list	*first;

	first = *head;

	/* Base case */
	if (first == NULL || first->next == NULL)
		return ;
	/* Split into sub-sections */
	st_split(first, &a, &b);
	/* Sort each sub-section */
	ft_lstsort(&a, cmp);
	ft_lstsort(&b, cmp);
	/* Merge sorted sub-sections */
	*head = st_merge(a, b, cmp);
}
