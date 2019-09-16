/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:54:03 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 16:02:39 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
    else
        return (1);
}

int main(void)
{
	int a;
	a = ft_recursive_factorial(8);
	printf("%d", a);
	return (0);
}
