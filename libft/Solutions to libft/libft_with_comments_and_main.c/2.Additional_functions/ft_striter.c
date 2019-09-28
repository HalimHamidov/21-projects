/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 07:06:26 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 07:06:30 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
void    ft_striter(char *s, void (*f)(char *))
{
    unsigned int i;
    
    i = 0;
    if (!s || !f)
    {
        return ;
    }
    while (s[i] != 0)
    {
        (*f)(&s[i++]);
    }
}

//ft_striter # applies f(char *) to every character in array s. No return.

void    ft_print_result(char const *s)
{
    int        len;
    
    len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

void    iter(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
    else if (*c >= 'A' && *c <= 'Z')
        *c = *c + 32;
}
char    *ft_strcpy(char *dst, const char *src)
{
    size_t i;
    
    i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
int        main()
{
    char    *str;
    str = (char *)malloc(sizeof(*str) * 12);
    ft_strcpy(str, "LoReM iPsUm");
    ft_print_result(str);
    ft_print_result("\n");
    ft_striter(str, &iter);
    ft_print_result(str);
    return (0);
}

// ft_striter
// Prototype
// void ft_striter(char*s,void(*f)(char*));
// Description
// Applies the function f to each character of the string passed as argument. Each character is passed by address to f to be modified if necessary.
// Param. #1
// The string to iterate.
// Param. #2
// The function to apply to each character of s.
// Return value
// None.
// Libc functions
// None.
