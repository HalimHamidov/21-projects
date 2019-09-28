/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:57:29 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 22:05:50 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

size_t        ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t    j;
    size_t    k;
    
    j = 0;
    k = 0;
    while (dst[j] && j < size)
        j++;
    while ((src[k]) && ((j + k + 1) < size))
    {
        dst[j + k] = src[k];
        k++;
    }
    if (j != size)
        dst[j + k] = '\0';
    return (j + ft_strlen(src));
}

int main()
{
    char *dest;
    if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
        return (0);
    memset(dest, 0, 15);
    memset(dest, 'r', 6);
    dest[11] = 'a';
    printf("%zu", ft_strlcat(dest, "lorem", 15));
    printf("\n%s", dest);
    
    memset(dest, 0, 15);
    memset(dest, 'r', 6);
    printf("\n%zu", ft_strlcat(dest, "", 15));
    printf("\n%s", dest);
    
    memset(dest, 0, 15);
    memset(dest, 'r', 6);
    dest[0] = '\0';
    dest[11] = 'a';
    printf("\n%zu", ft_strlcat(dest, "lorem ipsum", 15));
    printf("\n%s", dest);
    
    memset(dest, 0, 15);
    memset(dest, 'r', 6);
    dest[14] = 'a';
    printf("\n%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
    printf("\n%s", dest);
    
    memset(dest, '.', 15);
    memset(dest, 'r', 6);
    dest[10] = 'a';
    printf("\n%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
    printf("\n%s", dest);
    
    
    return(0);
}
//strlcat # append max (size - strlen(dst) - 1) characters of dst to src and NULL-terminate. Return total length of string it tried to create.
