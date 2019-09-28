/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:59:21 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 22:01:11 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    free(str);
    return(0);
}
//ft_memalloc # allocates memory in heap of size 'size'. Returns pointer to new space.
// ft_memalloc
// Prototype
// void* ft_memalloc(size_tsize);
// Description
// Allocates (with malloc(3)) and returns a “fresh” memory area. The memory allocated is initialized to 0. If the alloca- tion fails, the function returns NULL.
// Param. #1
// The size of the memory that needs to be allocated.
// Return value
// The allocated memory area.
// Libc functions
// malloc(3)
