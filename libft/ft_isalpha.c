/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:44:25 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/25 20:04:55 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static	int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int			ft_isalpha(int c)
{
	return (ft_islower(c) != 0 || ft_isupper(c) != 0);
}
