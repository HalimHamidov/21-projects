/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 05:06:28 by apearl            #+#    #+#             */
/*   Updated: 2019/09/08 05:14:19 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int ret;

	ret = 1;
	if (nb < 0 || nb >= 12)
		return (0);
	if (nb == 0 || nb ==1)
		return (1);
	while (nb >=1)
	{
		ret = ret * nb;
		nb--;
	}
	return (ret);
}

int main(void)
{
	printf("%d", ft_iterative_factorial(12));
	return (0);
}
