/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:49 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 21:16:30 by apearl           ###   ########.fr       */
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
char    *ft_strnew(size_t size)
{
    return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}
void    ft_strdel(char **as)
{
    if (as && *as)
    {
        free(*as);
        *as = NULL;
    }
}
int main()
{
    char *str;
    str = ft_strnew(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s,  Address = %p\n", str, str);
    ft_strdel(&str);
    printf("String = %s,  Address = %p\n", str, str);
    return(0);
}


//ft_strdel # free() char array 'as' and places pointer to NULL. No return.
// ft_strdel
// Prototype
// void ft_strdel(char**as);
// Description
// Takes as a parameter the address of a string that need to be freed with free(3), then sets its pointer to NULL.
// Param. #1
// The string’s address that needs to be freed and its pointer set to NULL.
// Return value
// None.
// Libc functions
// Free(3).
