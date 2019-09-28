/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:06:41 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:21:48 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int        ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}

int main(void)
{
    printf("1\n");
    int i = 0;
    while (i <= 47)
    {
        printf("%d", ft_isascii(i));
        i++;
    }
    printf("\n2\n");
    
    int j = '0';
    while (j <= '9')
    {
        printf("%d", ft_isascii(j));
        j++;
    }
    printf("\n3\n");
    int k = 58;
    while (k <= 64)
    {
        printf("%d", ft_isascii(k));
        k++;
    }
    printf("\n4\n");
    int l = 'A';
    while (l <= 'Z')
    {
        printf("%d", ft_isascii(l));
        l++;
    }
    printf("\n5\n");
    int m = 91;
    while (m <= 96)
    {
        printf("%d", ft_isascii(m));
        m++;
    }
    printf("\n6\n");
    int n = 'a';
    while (n <= 'z')
    {
        printf("%d", ft_isascii(n));
        n++;
    }
    printf("\n7\n");
    int o = 123;
    while (o <= 127)
    {
        printf("%d", ft_isascii(o));
        o++;
    }
    printf("\n8\n");
    int p = 128;
    while (p <= 138)
    {
        printf("%d", ft_isascii(p));
        p++;
    }
}
