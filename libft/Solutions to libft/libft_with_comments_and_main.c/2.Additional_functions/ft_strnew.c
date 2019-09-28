/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:44:49 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 22:45:53 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void    *ft_memalloc(size_t size);
char    *ft_strnew(size_t size)
{
    return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}
void    ft_memdel(void **ap)
{
    if (ap && *ap)
    {
        free(*ap);
        *ap = NULL;
    }
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

int main()
{
    char *str;
    /* Initial memory allocation */
    str = (char*)ft_memalloc(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s,  Address = %p\n", str, str);
    ft_memdel((void**)&str);
    printf("String = %s,  Address = %p\n", str, str);
    //free(str);
    ft_memdel((void**)&str);
    str = ft_strnew((15));
    printf("String = %s,  Address = %p\n", str, str);
    return(0);
}

//ft_strnew # allocates new memory space of size 'size' and fills it with '\0'. Returns pointer to new space.
// ft_strnew
// Prototype
// char* ft_strnew(size_tsize);
// Description
// Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’. Each character of the string is initialized at ’\0’. If the allocation fails the function returns NULL.
// Param. #1
// The size of the string to be allocated.
// Return value
// The string allocated and initialized to 0.
// Libc functions
// malloc(3)
