/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 02:10:41 by apearl            #+#    #+#             */
/*   Updated: 2019/09/15 02:16:04 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
        return (NULL);
    if (!(tab= (int *)malloc(sizeof(int) * (max - min))))
        return (NULL);
    i = 0;
    while (min < max)
    {
        tab[i] = min;
        min++;  // 6-7-8-9
        i++; // 1-2-3-4-5
    }
    return (tab);
}

int main(void)
{
    int*res;
    int i;
    
    i = 0;
    res = ft_range(5,10);
    while (i < 5)
    {
        printf("%d \n", res[i]);
        i++;
    }
      return (0);
}


        
