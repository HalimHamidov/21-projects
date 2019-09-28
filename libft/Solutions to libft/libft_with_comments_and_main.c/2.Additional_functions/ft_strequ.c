/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:17:06 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 21:17:44 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_print_result(int n)
{
    if (n == 0)
        write(1, "0", 1);
    else
        write(1, "1", 1);
}
int        ft_strcmp(const char *s1, const char *s2)
{
    unsigned char    *ptr1;
    unsigned char    *ptr2;
    size_t            i;
    
    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    i = 0;
    while (ptr1[i] || ptr2[i])
    {
        if (ptr1[i] != ptr2[i])
            return (ptr1[i] - ptr2[i]);
        i++;
    }
    return (0);
}

int        ft_strequ(char const *s1, char const *s2)
{
    if (s1 && s2)
        return (ft_strcmp(s1, s2) ? 0 : 1);
    return (0);
}

int main()
{
    ft_print_result(ft_strequ("salut", "salut"));
    write(1, "\n", 1);
    ft_print_result(ft_strequ("test", "tests"));
    write(1, "\n", 1);
    ft_print_result(ft_strequ("tests", "test"));
    write(1, "\n", 1);
    ft_print_result(ft_strequ("test", "tEst"));
    write(1, "\n", 1);
    ft_print_result(ft_strequ("", "test"));
    write(1, "\n", 1);
    ft_print_result(ft_strequ("test", ""));
    write(1, "\n", 1);
    ft_print_result(ft_strequ("", ""));
    return (0);
}

//ft_strequ # lexicographical comparaison between s1 and s2. Return 1 if equal, else 0.
// ft_strequ
// Prototype
// int ft_strequ(charconst*s1,charconst*s2);
// Description
// Lexicographical comparison between s1 and s2. If the 2 strings are identical the function returns 1, or 0 otherwise.
// Param. #1
// The first string to be compared.
// Param. #2
// The second string to be compared.
// Return value
// 1 or 0 according to if the 2 strings are identical or not.
// Libc functions
// None.
