/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:55:55 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/25 20:22:10 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *s;
	t_list *first;

	s = NULL;
	first = NULL;
	if (lst != NULL)
	{
		if (!(s = ft_lstnew(lst->content)))
			ft_lstclear(&s, del);
		s->content = f(lst->content);
		first = s;
		lst = lst->next;
		while (lst != NULL)
		{
			if (!(s->next = ft_lstnew(lst->content)))
				ft_lstclear(&first, del);
			s->next->content = f(lst->content);
			lst = lst->next;
			s = s->next;
		}
	}
	return (first);
}
