/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 06:35:45 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 06:46:17 by apearl           ###   ########.fr       */
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

void    ft_print_result(char const *s)
{
    int        len;
    
    len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

char    mapi(unsigned int i, char c)
{
    static int indexArray[11] = {0};
    
    if (i > 10 || indexArray[i] == 1)
        write(1, "wrong index\n", 12);
    else
        indexArray[i] = 1;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    else if (c >= 'A' && c <= 'Z')
        return (c + 32);
    else
        return (c);
}

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int        i;
    char    *str;
    
    i = 0;
    if (!s || !f)
        return (NULL);
    if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1)))
        return (NULL);
    ft_strcpy(str, s);
    while (str[i] != '\0')
    {
        str[i] = f(i, s[i]);
        i++;
    }
    return (str);
}

int        main()
{
    char    *str;
    char    *strmapi;
    
    str = (char *)malloc(sizeof(*str) * 12);
    ft_strcpy(str, "LoReM iPsUm");
    ft_print_result(str);
    ft_print_result("\n");
    strmapi = ft_strmapi(str, &mapi);
    ft_print_result(strmapi);
    if (strmapi == str)
        ft_print_result("\nA new string was not returned");
    if (strmapi[11] != '\0')
        ft_print_result("\nString is not null terminated");
    return (0);
}
//ft_strmapi # applies *(unsigned int, char) to every character in array and creates new array in heap with the return of *f(). Return pointer to new array.
// ft_strmapi
// Prototype
// char* ft_strmapi(charconst*s,char (*f)(unsigned int, char));
// Description
// Applies the function f to each character of the string passed as argument by giving its index as first argument to create a “fresh” new string (with malloc(3)) resulting from the suc- cessive applications of f.
// Param. #1
// The string to map.
// Param. #2
// The function to apply to each character of s and its index.
// Return value
// The “fresh” string created from the successive applications of f.
// Libc functions
// malloc(3)
