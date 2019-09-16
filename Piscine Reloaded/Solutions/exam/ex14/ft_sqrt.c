/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:07:14 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 17:15:47 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while ((sqrt * sqrt) < nb)
		sqrt++;
	if ((sqrt * sqrt) == nb)
		return (sqrt);
	return (0);
}

int main(void)
{
	int a = ft_sqrt(9);
	printf("%d", a);
}
/*
{
	int t;
	
	if (nb < 0)
		return (0);
	t = 1;
	while ((t * t) < nb)
		++t;
	if ((t*t) == nb)
		return (t);
	return (0);
}
*/

