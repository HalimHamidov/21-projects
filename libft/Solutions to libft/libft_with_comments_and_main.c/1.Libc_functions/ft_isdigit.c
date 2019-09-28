/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:12:25 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:23:19 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int        ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');//ascii code between 48 && 57
}



int main(void)
{
    printf("1\n");
    int i = 0;
    while (i <= 47)
    {
        printf("%d", ft_isdigit(i));
        i++;
    }
    printf("\n2\n");
    
    int j = '0';
    while (j <= '9')
    {
        printf("%d", ft_isdigit(j));
        j++;
    }
    printf("\n3\n");
    int k = 58;
    while (k <= 64)
    {
        printf("%d", ft_isdigit(k));
        k++;
    }
    printf("\n4\n");
    int l = 'A';
    while (l <= 'Z')
    {
        printf("%d", ft_isdigit(l));
        l++;
    }
    printf("\n5\n");
    int m = 91;
    while (m <= 96)
    {
        printf("%d", ft_isdigit(m));
        m++;
    }
    printf("\n6\n");
    int n = 'a';
    while (n <= 'z')
    {
        printf("%d", ft_isdigit(n));
        n++;
    }
    printf("\n7\n");
    int o = 123;
    while (o <= 127)
    {
        printf("%d", ft_isdigit(o));
        o++;
    }
    printf("\n8\n");
    int p = 48;
    while (p <= 57)
    {
        printf("%d", ft_isdigit(p));
        p++;
    }
}
//isdigit # tests for decimal digit character from '0' to '9'
