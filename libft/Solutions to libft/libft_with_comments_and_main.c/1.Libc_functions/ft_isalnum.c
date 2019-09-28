/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:01:18 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:03:17 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int        ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))//97-122  65-90
        return (1);
    else
        return (0);
}
int        ft_isdigit(int c)
{
    return (c >= '0' && c <= '9'); // 48-57
}

int        ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c)); // 48-57  65-90  97-12
}
int main(void)
{
    printf("1\n");
    int i = 0;
    while (i <= 47)
    {
        printf("%d", ft_isalnum(i));
        i++;
    }
    printf("\n2\n");
    
    int j = '0';
    while (j <= '9')
    {
        printf("%d", ft_isalnum(j));
        j++;
    }
    printf("\n3\n");
    int k = 58;
    while (k <= 64)
    {
        printf("%d", ft_isalnum(k));
        k++;
    }
    printf("\n4\n");
    int l = 'A';
    while (l <= 'Z')
    {
        printf("%d", ft_isalnum(l));
        l++;
    }
    printf("\n5\n");
    int m = 91;
    while (m <= 96)
    {
        printf("%d", ft_isalnum(m));
        m++;
    }
    printf("\n6\n");
    int n = 'a';
    while (n <= 'z')
    {
        printf("%d", ft_isalnum(n));
        n++;
    }
    printf("\n7\n");
    int o = 123;
    while (o <= 127)
    {
        printf("%d", ft_isalnum(o));
        o++;
    }
}
//isalnum # tests for alpha or digit character
