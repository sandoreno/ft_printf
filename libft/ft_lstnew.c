/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:59:14 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/25 17:16:29 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *arr;

	if (!(arr = malloc(sizeof(t_list))))
		return (NULL);
	arr->content = content;
	arr->next = NULL;
	return (arr);
}
