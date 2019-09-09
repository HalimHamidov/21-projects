/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_iterative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 08:07:48 by apearl            #+#    #+#             */
/*   Updated: 2019/09/08 08:48:45 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_iterative(int nb)
{
	int ret;

	ret = 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (nb >= 1)
	{
		ret *= nb;
		nb = nb - 1;
	}
	return (ret);
}

int ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int main (void)
{
	printf("%d  %d  %d  %d  %d\n", ft_is_iterative(0), ft_is_iterative(1), ft_is_iterative(2), ft_is_iterative(10), ft_is_iterative(12));
	
	printf(" %d\n", ft_recursive_factorial(10));
	return (0);
}

