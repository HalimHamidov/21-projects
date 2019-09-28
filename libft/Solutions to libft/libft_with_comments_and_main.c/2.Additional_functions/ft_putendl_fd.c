/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:35:32 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 20:44:15 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_putendl_fd_fd
// Prototype
// void ft_putendl_fd_fd(char const *s, int fd);
// Description
// Outputs the string s to the file descriptor fd followed by a ’\n’.
// Param. #1
// The string to output.
// Param. #2
// The file descriptor.
// Return value
// None.
// Libc functions
// write(2).
#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putendl_fd(char const *s, int fd)
{
    if (s)
        write(fd, s, ft_strlen(s));
    write(fd, "\n", 1);
}
int        main()
{
    ft_putendl_fd("lorem ipsum dolor sit amet", 2);
    ft_putendl_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
    ft_putendl_fd("", 2);
    ft_putendl_fd("lorem ipsum do\0lor sit amet", 1);
    return (0);
}

/*This function will display the string s on the standard output followed by a
 *'\n', which is a new line. We do this by using our ft_putstr and ft_putchar
 * functions that we previously made. We use our ft_putstr on our string s to
 * display it on the standard output. Then we use our ft_putchar to have our
 * string followed by a new line.*/
