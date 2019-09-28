/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:30:43 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 20:33:32 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_putchar_fd # puts single charater on fd.
#include <stdlib.h>
#include <unistd.h>

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, sizeof(c));
}


int        main()
{
    int        i;
    
    i = 0;
    while (i <= 47)
    {
        ft_putchar_fd(i, 2);
        i++;
    }
    write(1,"\n",1);
    int j = '0';
    while (j <= '9')
    {
        ft_putchar_fd(j, 1);
        j++;
    }
    write(1,"\n",1);
    int k = 58;
    while (k <= 64)
    {
        ft_putchar_fd(k, 2);
        k++;
    }
    write(1,"\n",1);
    int l = 'A';
    while (l <= 'Z')
    {
        ft_putchar_fd(l, 1);
        l++;
    }
    write(1,"\n",1);
    int m = 91;
    while (m <= 96)
    {
        ft_putchar_fd(m, 2);
        m++;
    }
    write(1,"\n",1);
    int n = 'a';
    while (n <= 'z')
    {
        ft_putchar_fd(n, 1);
        n++;
    }
    write(1,"\n",1);
    int o = 123;
    while (o <= 127)
    {
        ft_putchar_fd(o, 2);
        o++;
    }
}

/*
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdio.h>
 
 void    ft_putchar_fd(char c, int fd)
 {
 write(fd, &c, sizeof(c));
 }
 
 void    ft_putnbr(int n)
 {
 */
/*    if (n < 0)
 {
 ft_putchar_fd('-', 1);
 n = -n;
 }
 if (n < 10)
 ft_putchar_fd(n + '0', 1);
 else
 {
 ft_putnbr(n / 10);
 ft_putnbr(n % 10);
 }
 }
 */

/*
 int        main()
 {
 int        i;
 int fd;
 
 fd = open("test1", O_WRONLY);
 //    ft_putchar_fd("c", fd);
 printf("%d\n",fd);
 
 i = 33;
 while (i <= 47)
 {
 ft_putchar_fd(i, fd);
 i++;
 }
 }
 */

// ft_putchar_fd
// Prototype
// void ft_putchar_fd(charc,intfd);
// Description
// Outputs the char c to the file descriptor fd.
// Param. #1
// The character to output.
// Param. #2
// The file descriptor.
// Return value
// None.
// Libc functions
// write(2).
