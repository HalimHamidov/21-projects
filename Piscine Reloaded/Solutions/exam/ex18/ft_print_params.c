/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:09:54 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 19:15:06 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}


int main(int ac, char *argv[])
{
    int i;
    
    i = 1;
    while (ac > i)
    {
        while (*argv[i])
            ft_putchar(*argv[i]++);
        i++;
        ft_putchar('\n');
    }
 return (0);
}

/*
#include <stdio.h>

const int size = 4;

int main()
{
    
    // array of pointers to a character
    // to store a list of strings
    char* names[] = {
        "amit",
        "amar",
        "ankit",
        "akhil"
    };
    
    int i = 0;
    
    while (i < size)
    {
        printf("%s\n", names[i]);
        i++;
    }
} 
*/
