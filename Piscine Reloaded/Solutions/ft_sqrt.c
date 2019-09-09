/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 09:01:03 by apearl            #+#    #+#             */
/*   Updated: 2019/09/08 09:18:46 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1; // must condition for recursions it must have stop number for recursion to stop counting on
	while ((sqrt * sqrt) < nb) // we assume that number sqrt is multiplying itself to itself until we get the number nb in our example so that sqrt is smaller than nb, the loop condition goes here, it repeats 
		++sqrt;// we increment the sqrt number until we meet the condition above and below
    if ((sqrt * sqrt) == nb) // here's the main condition meaning that number multiplying to itself we get the result nb , so if it's the result than the next step is return stopping the recursion
		return (sqrt);// here we get the answer and can print to the console
	return (0);
}

int main(void)
{
	printf("%d", ft_sqrt(9));// only the here int main displays the output of our function and program
	return (0);// stop the program and don't show anything more thanks for your attention
}
