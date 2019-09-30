/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:05:53 by apearl            #+#    #+#             */
/*   Updated: 2019/09/28 23:14:02 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_map(t_list *elem)
{
	int			i;
	t_list		*new_elem;

	new_elem = ft_lstnew(elem->content, elem->content_size);
	if (!new_elem)
		return (0);
	i = 0;
	while (((char *)new_elem->content)[i])
	{
		((char *)new_elem->content)[i] = 'c';
		i++;
	}
	return (new_elem);
}
