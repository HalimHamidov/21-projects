/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:10:40 by apearl            #+#    #+#             */
/*   Updated: 2019/09/26 00:41:29 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*res;
	char	*str;

	str = "0123456789";
	len = n < 0 ? 1 : 0;
	nb = n < 0 ? -(long)n : n;
	len = ft_nbrlen(nb, len);
	len = (n == 0) ? 1 : len;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	while (nb > 0)
	{
		res[--len] = str[nb % 10];
		nb /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
