/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:10:40 by apearl            #+#    #+#             */
/*   Updated: 2019/09/20 17:50:46 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static    int    ft_nbrlen(long c, int len)
{
    int    base;
    
    base = 10;
    while (c > 0)
    {
        c /= base;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)//ft_itoa # takes int n and returns new array of chars.
{
    int        len;
    long    nb;
    char    *res;
    char    *str;
    
    str = "0123456789";// base string
    len = n < 0 ? 1 : 0;// when the integer is - we then put len = 1;
    nb = n < 0 ? -(long)n : n;//use the temp (nb) long variable to perform the operation.
    len = ft_nbrlen(nb, len);//will provide the length of the integer.
    len = (n == 0) ? 1 : len;// corner case for 0.
    if (!(res = (char *)malloc(sizeof(char) * (len + 1))))// allocate the heap memory.
        return (NULL);
    if (n == 0)// for corner case (0)
        res[0] = '0';
    res[len] = '\0';// terminate the last char of the string.
    while (nb > 0)// iteration for the value.
    {
        res[--len] = str[nb % 10];
        nb /= 10;
    }
    if (n < 0)// if the number is negative put '-' at first place.
        res[0] = '-';
    return (res);
}

int main()
{
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(9));
    printf("%s\n", ft_itoa(-9));
    printf("%s\n", ft_itoa(10));
    printf("%s\n", ft_itoa(-10));
    printf("%s\n", ft_itoa(8124));
    printf("%s\n", ft_itoa(-9874));
    printf("%s\n", ft_itoa(543000));
    printf("%s\n", ft_itoa(-2147483648LL));
    printf("%s\n", ft_itoa(2147483647));
    return (0);
}

// ft_itoa
// Prototype
// char* ft_itoa(intn);
// Description
// Allocate (with malloc(3)) and returns a “fresh” string end- ing with ’\0’ representing the integer n given as argument. Negative numbers must be supported. If the allocation fails, the function returns NULL.
// Param. #1
// The integer to be transformed into a string.
// Return value
// The string representing the integer passed as argument.
// Libc functions
// malloc(3)
