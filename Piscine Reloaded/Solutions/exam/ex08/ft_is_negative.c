/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:52:31 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 13:02:37 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

void	ft_is_negative (int n)
{
	if (n < 0)
		ft_putchar ('N');
	else 
		ft_putchar ('P');
}

int main(void)
{
	ft_is_negative(99);
	ft_putchar('\n');
	ft_is_negative(-99);
	return (0);
}
