/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:21:10 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 20:25:33 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    return(0);
}

//ft_memdel # free() memory zone of pointed to by **ap. No return.
// ft_memdel
// Prototype
// void ft_memdel(void**ap);
// Description
// Takes as a parameter the address of a memory area that needs to be freed with free(3), then puts the pointer to NULL.
// Param. #1
// A pointer’s address that needs its memory freed and set to NULL.
// Return value
// None.
// Libc functions
// free(3).
