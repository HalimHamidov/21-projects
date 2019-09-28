/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 07:07:09 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 07:07:19 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}
char    *ft_strcat(char *s1, const char *s2)
{
    size_t i;
    
    i = ft_strlen(s1);
    while ((s1[i] = *s2++))
        i++;
    return (s1);
}
void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n--)
        *ptr++ = '\0';
}

void    *ft_memalloc(size_t size)
{
    void *ptr;
    
    if ((ptr = malloc(size)))
        ft_bzero(ptr, size);
    return (ptr);
}

char    *ft_strnew(size_t size)
{
    return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}

void    ft_print_result(char const *s)
{
    int        len;
    
    len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *res;
    
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
    if (!res)
        return (NULL);
    ft_strcpy(res, s1);
    ft_strcat(res, s2);
    return (res);
}

int        main()
{
    char    s1[] = "lorem ipsum";
    char    s2[] = "dolor sit amet";
    
    ft_print_result(ft_strjoin(s1, s2));
    write(1, "\n", 1);
    s1[0] = '\0';
    ft_print_result(ft_strjoin(s1, s2));
    write(1, "\n", 1);
    char    st1[] = "lorem ipsum";
    char    st2[] = "dolor sit amet";
    st2[0] = '\0';
    ft_print_result(ft_strjoin(st1, st2));
    write(1, "\n", 1);
    char    str1[] = "lorem ipsum";
    char    str2[] = "dolor sit amet";
    str1[0] = '\0';
    str2[0] = '\0';
    ft_print_result(ft_strjoin(str1, str2));
    return (0);
}

/*
 ft_strjoin # allocates memory in heap and returns concatenation of s1 and s2 NULL-terminating string. Return result or NULL.
 ft_strjoin
 Prototype
 char * ft_strjoin(char const *s1, char const *s2);
 Description
 Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’, result of the concatenation of s1 and s2. If the allocation fails the function returns NULL.
 Param. #1
 The prefix string.
 Param. #2
 The suffix string.
 Return value
 The “fresh” string result of the concatenation of the 2 strings.
 Libc functions
 malloc(3)
 */
