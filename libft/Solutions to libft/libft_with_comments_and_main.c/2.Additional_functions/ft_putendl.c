/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:18:10 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/07/04 12:18:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_putendl
// Prototype
// void ft_putendl(char const *s);
// Description
// Outputs the string s to the standard output followed by a ’\n’.
// Param. #1
// The string to output.
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
void    ft_putendl(char const *s)
{
    if (s)
        write(1, s, ft_strlen(s));
    write(1, "\n", 1);
}
int        main()
{
    ft_putendl("lorem ipsum dolor sit amet");
    ft_putendl("  lorem\nipsum\rdolor\tsit amet  ");
    ft_putendl("");
    ft_putendl("lorem ipsum do\0lor sit amet");
    return (0);
}
