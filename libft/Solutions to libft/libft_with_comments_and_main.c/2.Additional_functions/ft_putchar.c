/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:34:26 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 20:35:02 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int main()
{
    int i = 0;
    while (i <= 47)
    {
        ft_putchar(i);
        i++;
    }
    ft_putchar('\n');
    int j = '0';
    while (j <= '9')
    {
        ft_putchar(j);
        j++;
    }
    ft_putchar('\n');
    int k = 58;
    while (k <= 64)
    {
        ft_putchar(k);
        k++;
    }
    ft_putchar('\n');
    int l = 'A';
    while (l <= 'Z')
    {
        ft_putchar(l);
        l++;
    }
    ft_putchar('\n');
    int m = 91;
    while (m <= 96)
    {
        ft_putchar(m);
        m++;
    }
    ft_putchar('\n');
    int n = 'a';
    while (n <= 'z')
    {
        ft_putchar(n);
        n++;
    }
    ft_putchar('\n');
    int o = 123;
    while (o <= 127)
    {
        ft_putchar(o);
        o++;
    }
    
    return (0);
}
// ft_putchar
// Prototype
// void ft_putchar(charc);
// Description
// Outputs the character c to the standard output.
// Param. #1
// The character to output.
// Return value
// None.
// Libc functions
// write(2).

