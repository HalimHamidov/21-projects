/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:06:27 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 23:06:34 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    ft_print_result(char const *s)
{
    int        len;
    
    len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

char        *ft_strsub(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    char            *str;
    
    if (!s)
        return (NULL);
    i = 0;
    str = (char *)malloc(sizeof(char) * len + 1);
    if (str == NULL)
        return (NULL);
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int        main()
{
    char    str[] = "lorem ipsum dolor sit amet";
    ft_print_result(ft_strsub(str, 0, 10));
    write(1, "\n", 1);
    ft_print_result(ft_strsub(str, 7, 10));
    write(1, "\n", 1);
    ft_print_result(ft_strsub(str, 7, 0));
    write(1, "\n", 1);
    ft_print_result(ft_strsub(str, 0, 0));
    return (0);
}

//ft_strsub # allocates memory in heap and from start of s, copies len bytes. Return copy.
/*ft_strsub
 Prototype
 char * ft_strsub(char const *s, unsigned int start, size_t len);
 Description
 Allocates (with malloc(3)) and returns a “fresh” substring from the string given as argument. The substring begins at indexstart and is of size len. If start and len aren’t refer- ing to a valid substring, the behavior is undefined. If the allocation fails, the function returns NULL.
 Param. #1
 The string from which create the substring.
 Param. #2
 The start index of the substring.
 Param. #3
 The size of the substring.
 Return value
 The substring.
 Libc functions
 malloc(3)
 */
