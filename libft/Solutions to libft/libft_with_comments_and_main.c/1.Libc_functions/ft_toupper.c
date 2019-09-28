/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:10:12 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 23:11:43 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int        ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

int main(void)
{
    printf("1\n");
    int i = 0;
    while (i <= 47)
    {
        printf("%c", ft_toupper(i));
        i++;
    }
    printf("\n2\n");
    
    int j = '0';
    while (j <= '9')
    {
        printf("%c", ft_toupper(j));
        j++;
    }
    printf("\n3\n");
    int k = 58;
    while (k <= 64)
    {
        printf("%c", ft_toupper(k));
        k++;
    }
    printf("\n4\n");
    int l = 'A';
    while (l <= 'Z')
    {
        printf("%c", ft_toupper(l));
        l++;
    }
    printf("\n5\n");
    int m = 91;
    while (m <= 96)
    {
        printf("%c", ft_toupper(m));
        m++;
    }
    printf("\n6\n");
    int n = 'a';
    while (n <= 'z')
    {
        printf("%c", ft_toupper(n));
        n++;
    }
    printf("\n7\n");
    int o = 123;
    while (o <= 127)
    {
        printf("%c", ft_toupper(o));
        o++;
    }
}

//toupper # converts lower-case alpha to upper-case
