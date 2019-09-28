/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:54:24 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 20:57:29 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char const *s)
{
    size_t    i;
    
    i = 0;
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
}
void    ft_putnbr(int n)
{
    if (n == -2147483648)
        ft_putstr("-2147483648");
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(-n);
    }
    else if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
    else
        ft_putchar(n + '0');
}


int        main()
{
    
    ft_putnbr(0);
    write(1, "\n", 1);
    ft_putnbr(5);
    write(1, "\n", 1);
    ft_putnbr(-5);
    write(1, "\n", 1);
    ft_putnbr(42);
    write(1, "\n", 1);
    ft_putnbr(-57);
    write(1, "\n", 1);
    ft_putnbr(164189);
    write(1, "\n", 1);
    ft_putnbr(-987441);
    write(1, "\n", 1);
    ft_putnbr(2147483647);
    write(1, "\n", 1);
    ft_putnbr(-2147483648LL);
    return (0);
}
// ft_putnbr
// Prototype
// void ft_putnbr(intn);
// Description
// Outputs the integer n to the standard output.
// Param. #1
// The integer to output.
// Return value
// None.
// Libc functions
// write(2).
