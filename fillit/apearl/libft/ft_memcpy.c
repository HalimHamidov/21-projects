/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 07:14:13 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 07:18:32 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (!src && !dst)
		return (dst);
	i = -1;
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
	return (dst);
}
