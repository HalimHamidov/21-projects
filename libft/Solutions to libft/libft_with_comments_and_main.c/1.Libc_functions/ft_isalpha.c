/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:05:30 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 23:39:14 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void    ft_print_result(int n)
{
    if (n)
        write(1, "1", 1);
    else
        write(1, "0", 1);
}

int        ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
        printf("%d", ft_isalpha(i));
        i++;
    }
    printf("\n2\n");
    
    int j = '0';
    while (j <= '9')
    {
        printf("%d", ft_isalpha(j));
        j++;
    }
    printf("\n3\n");
    int k = 58;
    while (k <= 64)
    {
        printf("%d", ft_isalpha(k));
        k++;
    }
    printf("\n4\n");
    int l = 'A';
    while (l <= 'Z')
    {
        printf("%d", ft_isalpha(l));
        l++;
    }
    printf("\n5\n");
    int m = 91;
    while (m <= 96)
    {
        printf("%d", ft_isalpha(m));
        m++;
    }
    printf("\n6\n");
    int n = 'a';
    while (n <= 'z')
    {
        printf("%d", ft_isalpha(n));
        n++;
    }
    printf("\n7\n");
    int o = 123;
    while (o <= 127)
    {
        printf("%d", ft_isalpha(o));
        o++;
    }
}

//isalpha # tests for any char in alphabet upper or lower.
