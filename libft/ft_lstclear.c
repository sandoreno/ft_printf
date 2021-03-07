/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:13:10 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/27 00:32:05 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	if (lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		if (temp->content != NULL)
			del(temp->content);
		free(temp);
		temp = temp->next;
	}
	(*lst) = NULL;
}
