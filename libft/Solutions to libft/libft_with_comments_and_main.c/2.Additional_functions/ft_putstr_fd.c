/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:58:19 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 20:59:03 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_putstr_fd_fd # puts string on fd.
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

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr_fd(char const *s, int fd)
{
    if (s)
        write(fd, s, ft_strlen(s));
}

int        main()
{
    ft_putstr_fd("lorem ipsum dolor sit amet", 2);
    write(1, "\n", 1);
    ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
    write(1, "\n", 1);
    ft_putstr_fd("", 2);
    ft_putstr_fd("lorem ipsum do\0lor sit amet", 1);
    write(1, "\n", 1);
    return (0);
}

// ft_putstr_fd
// Prototype
// void ft_putstr_fd(charconst*s,intfd);
// Description
// Outputs the string s to the file descriptor fd.
// Param. #1
// The string to output.
// Param. #2
// The file descriptor.
// Return value
// None.
// Libc functions
// write(2).
