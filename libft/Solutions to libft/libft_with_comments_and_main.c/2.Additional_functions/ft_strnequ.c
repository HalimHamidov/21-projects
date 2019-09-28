/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:43:53 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 22:44:38 by apearl           ###   ########.fr       */
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
int        ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char    *ptr1;
    unsigned char    *ptr2;
    size_t            i;
    
    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    i = 0;
    while ((ptr1[i] || ptr2[i]) && i < n)
    {
        if (ptr1[i] != ptr2[i])
            return (ptr1[i] - ptr2[i]);
        i++;
    }
    return (0);
}

int        ft_strnequ(char const *s1, char const *s2, size_t n)
{
    if (s1 && s2)
        return (ft_strncmp(s1, s2, n) ? 0 : 1);
    return (0);
}

int main()
{
    ft_print_result(ft_strnequ("salut", "salut", 50));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("test", "tests", 6));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("tests", "test", 6));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("test", "tEst", 6));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("", "test", 6));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("test", "", 6));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("", "", 6));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("test", "test", 2));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("tew", "tez", 2));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("", "", 0));
    write(1, "\n", 1);
    ft_print_result(ft_strnequ("abcd", "zxyw", 0));
    return (0);
}

// ft_strnequ
// Prototype
// int ft_strnequ(charconst*s1,charconst*s2, size_t n);
// Description
// Lexicographical comparison between s1 and s2 up to n char- acters or until a ’\0’ is reached. If the 2 strings are identical, the function returns 1, or 0 otherwise.
// Param. #1
// The first string to be compared.
// Param. #2
// The second string to be compared.
// Param. #3
// The maximum number of characters to be compared.
// Return value
// 1 or 0 according to if the 2 strings are identical or not.
// Libc functions
// None.
