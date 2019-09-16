/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:20:55 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 13:27:50 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int tmp;
    
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
    int a, b;
    
    a = 10; 
	b = 2;
	printf("before swap:\n a = %d ,b = %d \n", a, b);
    ft_swap(&a, &b);
    printf("after swap:\n a = %d ,b = %d \n", a, b);
    return (0);
}