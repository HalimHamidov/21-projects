/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:16:53 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 17:20:21 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{ 
	write(1, &c, 1);
}

/*
void	ft_putstr(char *str)
{
    int i;
    
    i = 0;
	while (*str)
	{
		ft_putchar(*str++);
	}
}
 */
void    ft_putstr(char *s)
{
    while (*s)
    {
        write(1, &*s++, 1);
    }
}

int main(void)
{
	char a[] = {"halim"};
	ft_putstr(a);
}
