/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:07:28 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 23:07:31 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
char        *ft_strtrim(char const *s)
{
    unsigned int    i;
    unsigned int    j;
    unsigned int    k;
    char            *str;
    
    i = 0;
    k = 0;
    if (!s)
        return (NULL);
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        i++;
    if (s[i] == '\0')
        return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
    j = ft_strlen(s) - 1;
    while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
        j--;
    if (!(str = (char *)malloc(sizeof(char) * (j - i + 2))))
        return (NULL);
    while (k < j - i + 1)
    {
        str[k] = s[i + k];
        k++;
    }
    str[k] = '\0';
    return (str);
}
void    ft_print_result(char const *s)
{
    int        len;
    
    len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

int        main()
{
    char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
    ft_print_result(ft_strtrim(s1));
    write(1, "\n", 1);
    char s2[] = "lorem ipsum dolor sit amet \n \t ";
    ft_print_result(ft_strtrim(s2));
    write(1, "\n", 1);
    char s3[] = " \n \t lorem ipsum dolor sit amet";
    ft_print_result(ft_strtrim(s3));
    write(1, "\n", 1);
    char s4[] = "  \n  \t  lorem \n ipsum \t dolor \n sit \t amet  \t \n ";
    ft_print_result(ft_strtrim(s4));
    write(1, "\n", 1);
    char s5[] = "          ";
    ft_print_result(ft_strtrim(s5));
    return (0);
}

/*
 ft_strtrim # allocates memory in heap and returns copy after removing characters ' ', '\n' and '\t' at begining or end of string. Return result or NULL.
 ft_strtrim
 Prototype
 char * ft_strtrim(char const *s);
 Description
 Allocates (with malloc(3)) and returns a copy of the string given as argument without whitespaces at the beginning or at the end of the string. Will be considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s has no whites- paces at the beginning or at the end, the function returns a copy of s. If the allocation fails the function returns NULL.
 Param. #1
 The string to be trimed.
 Return value
 The “fresh” trimmed string or a copy of s.
 Libc functions
 malloc(3)
 
 */

