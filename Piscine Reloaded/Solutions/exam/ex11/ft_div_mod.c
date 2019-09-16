/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:07:14 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 15:08:29 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main(void)
{
    int a, b, div, mod;
    
    a = 10; b = 2;
    ft_div_mod(a, b, &div, &mod);
    printf("%d\n", div);
    printf("%d", mod);
    return (0);
}
