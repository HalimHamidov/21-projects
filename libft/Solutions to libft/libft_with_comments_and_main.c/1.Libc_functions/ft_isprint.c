/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:27:25 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 23:46:57 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int        ft_isprint(int c)
{
    if (c >= ' ' && c <= '~') //return (c >= 32 && c <= 126);
        return (1);
    else
        return (0);
}
int main(void)
{
    printf("1\n");
    int i = 0;
    while (i <= 47)
    {
        printf("%d", ft_isprint(i));
        i++;
    }
    printf("\n2\n");
    
    int j = '0';
    while (j <= '9')
    {
        printf("%d", ft_isprint(j));
        j++;
    }
    printf("\n3\n");
    int k = 58;
    while (k <= 64)
    {
        printf("%d", ft_isprint(k));
        k++;
    }
    printf("\n4\n");
    int l = 'A';
    while (l <= 'Z')
    {
        printf("%d", ft_isprint(l));
        l++;
    }
    printf("\n5\n");
    int m = 91;
    while (m <= 96)
    {
        printf("%d", ft_isprint(m));
        m++;
    }
    printf("\n6\n");
    int n = 'a';
    while (n <= 'z')
    {
        printf("%d", ft_isprint(n));
        n++;
    }
    printf("\n7\n");
    int o = 123;
    while (o <= 127)
    {
        printf("%d", ft_isprint(o));
        o++;
    }
}
//isprint # tests for any printing character from octal 040 to 176 inclusive
