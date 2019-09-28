/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:44:48 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 23:41:01 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_putnbr_fd # puts number on fd.

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

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, sizeof(c));
}

void    ft_putstr_fd(char const *s, int fd)
{
    if (s)
        write(fd, s, ft_strlen(s));
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
        ft_putstr_fd("-2147483648", fd);
    else if (n < 0)
    {
        ft_putchar_fd('-', fd);
        ft_putnbr_fd(-n, fd);
    }
    else if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putchar_fd(n % 10 + '0', fd);
    }
    else
        ft_putchar_fd(n + '0', fd);
}

int        main()
{
    ft_putnbr_fd(0, 2);
    write(1, "\n", 1);
    ft_putnbr_fd(5, 1);
    write(1, "\n", 1);
    ft_putnbr_fd(-5, 2);
    write(1, "\n", 1);
    ft_putnbr_fd(42, 1);
    write(1, "\n", 1);
    ft_putnbr_fd(-57, 2);
    write(1, "\n", 1);
    ft_putnbr_fd(164189, 1);
    write(1, "\n", 1);
    ft_putnbr_fd(-987441, 2);
    write(1, "\n", 1);
    ft_putnbr_fd(2147483647, 1);
    write(1, "\n", 1);
    ft_putnbr_fd(-2147483648LL, 2);
    return (0);
}



// ft_putnbr_fd
// Prototype
// void ft_putnbr_fd(intn,intfd);
// Description
// Outputs the integer n to the file descriptor fd.
// Param. #1
// The integer to print.
// Param. #2
// The file descriptor.
// Return value
// None.
// Libc functions
// write(2).
// #include "libft.h"

// /*This function will display the integer n on the standard output. This
//  * function is similar to our ft_itoa function because we will be doing it
//  * recursively. We will be breaking down int number as a whole into individual
//  * single digit numbers and we will convert those int numbers into characters
//  * that we will display on the standard output using our ft_putchar function.*/

// void        ft_putnbr(int n)
// {
//     /*We start by seeing if the int passed in parameter is -2147483648. The
//      * number 2147483648 is the largest number an int variable can possibly
//      * hold. When a negative sign is placed in front of it our function is not
//      * able to handle it. So we check to see if a negative version has been
//      * given and if so we just immediately return it.*/
//     if (n == -2147483648)
//         ft_putstr("-2147483648");
//     /*If -2147483648 has not been given we then check to see if another
//      * negative number has been given. If the number is negative we immediately
//      * use ft_putchar('-') to display the minus sign to the standard output. We
//      * then call ft_putnbr again on a negative version of the variable n,
//      * making it a positive number and we run the function again from the start.
//      * If our given number is not negative we move to the next else if.*/
//     else if (n < 0)
//     {
//         ft_putchar('-');
//         ft_putnbr(-n);
//     }
//     /*We now check to see if the number is greater than or equal to 10. If it
//      * is we begin to break down the number recursively to each individual
//      * digit, where we will then convert it into a character. Similar to our
//      * breakdown recursively in our ft_itoa we are one again going to use a
//      * division by 10 and a modulus by 10. The division by 10 will take us
//      * further into the recursion until we finally reach the very first number
//      * in our int. If you look at the modulus 10 we use a + '0' to convert
//      * the number into a char value. Though this seems like it will be put to
//      * the standard output immediately, it will actually happen last since it
//      * will be the last thing to happen when we backtrack out of our recursion.
//      * If you are having difficulty understanding recusion you should write
//      * out the steps this function will take on a piece of paper. Like ft_itoa
//      * it should make an image that looks like a binary tree. At then end of
//      * our deconstruction of digits we will add '0' to the int to make it have
//      * a character value. We will use ft_putchar on this digit to display it
//      * on the standard output and then back track through our recursion until
//      * every individual digit has been displayed.*/
//     else if (n >= 10)
//     {
//         ft_putnbr(n / 10);
//         ft_putchar(n % 10 + '0');
//     }
//     else
//         ft_putchar(n + '0');
// }

