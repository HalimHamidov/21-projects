/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:00:28 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:01:00 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n--)
        *ptr++ = '\0';
}
int main(void) {
    char str[] = "Hey William";
    ft_bzero(str, 5);
    printf("%s\n", str);
    unsigned char src[15] = "0123456789";
    ft_bzero(src, 5);
    printf("memset sys: %s\n", src);
    return 0;
}

/*
 http://ru.manpages.org/bzero/3
 bzero(3)
 записывает байты с нулевым значением
 ОБЗОР
 #include <strings.h>
 
 void bzero(void *s, size_t n);
 ОПИСАНИЕ
 Функция bzero() устанавливает первые n байт области, начинающейся с s, в ноль (байты, содержащие '\0')).
 */
