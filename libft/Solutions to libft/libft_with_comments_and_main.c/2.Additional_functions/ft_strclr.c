/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:14:28 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 21:14:32 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_strclr(char *s)
{
    if (s)
        while (*s)
            *s++ = '\0';
}

int main(void)
{
    char        str[] = "Hello";
    printf("%s\n", str);
    ft_strclr(str);
    printf("%s", str);
    return (0);
}
/*
 ft_strclr # fills memory space with '\0'. No return.
 i = 0;
 while (i < 6)
 {
 if (str[i] != '\0')
 return (0);
 i = i + 1;
 }
 printf("%x", str[i]);
 */
// ft_strclr
// Prototype
// void ft_strclr(char*s);
// Description
// Sets every character of the string to the value ’\0’.
// Param. #1
// The string that needs to be cleared.
// Return value
// None.
// Libc functions
// None.
