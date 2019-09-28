/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:09:42 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 07:36:56 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_print_result(char const *s)
{
    int        len;
    
    len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

char    map(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    else if (c >= 'A' && c <= 'Z')
        return (c + 32);
    else
        return (c);
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

char        *ft_strmap(char const *s, char (*f)(char))
{
    unsigned int    i;
    char            *str;
    
    i = 0;
    if (!s || !f)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
    if (str == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        str[i] = f(s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

int        main()
{
    char    *str;
    char    *strmap;
    
    str = (char *)malloc(sizeof(*str) * 12);
    ft_strcpy(str, "LoReM iPsUm");
    ft_print_result(str);
    ft_print_result("\n");
    strmap = ft_strmap(str, &map);
    ft_print_result(strmap);
    if (strmap == str)
        ft_print_result("\nA new string was not returned");
    if (strmap[11] != '\0')
        ft_print_result("\nString is not null terminated");
    return (0);
}
//ft_strmap # applies *f(char) to every character in array and creates new array in heap with the return of *f(). Return pointer to new array.
// ft_strmap
// Prototype
// char* ft_strmap(charconst*s,char(*f)(char));
// Description
// Applies the function f to each character of the string given as argument to create a “fresh” new string (with malloc(3)) resulting from the successive applications of f.
// Param. #1
// The string to map.
// Param. #2
// The function to apply to each character of s.
// Return value
// The “fresh” string created from the successive applications of f.
// Libc functions
// malloc(3)
