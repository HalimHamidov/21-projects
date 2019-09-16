/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:23:34 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 15:41:10 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int ret;

	ret = 1;
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	while (nb >= 1)
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
/The factorial function is defined by the product

//{\displaystyle n!=1\cdot 2\cdot 3\cdots (n-2)\cdot (n-1)\cdot n,}{\displaystyle n!=1\cdot 2\cdot 3\cdots (n-2)\cdot (n-1)\cdot n,}