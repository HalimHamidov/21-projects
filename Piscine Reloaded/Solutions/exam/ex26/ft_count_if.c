/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 06:16:31 by apearl            #+#    #+#             */
/*   Updated: 2019/09/15 06:34:59 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
int	ft_count_if(char **tab, int(*f)(char*))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

int ft_islower(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}

int main(void)
{
    char *arr[] = { "one", "two", "D" };
    printf("ft_any: %d", ft_count_if(arr, &ft_islower));
    return 0;
}
*/
#include "stdio.h"

int  ft_str_is_alpha(char *str)
{
    int index;
    index = 0;
    while(str[index] !='\0')
    {
        if (!((str[index]>='a'&& str[index]<='z')||(str[index]>='A'&& str[index]<='Z')))
        {
            return 0;
        }
        index++;
    }
    
    return 1;
}
int ft_count_if(char **tab, int(*f)(char*))
{
    int i;
    i =0;
    int count =0;
    while(tab[i] != 0)
    {
        if(f(tab[i]) == 1)
            count++;
        i++;
    }
    return count;
}
int main(void)
{
    
    char *array[]={"etyy", "yfyhjj", "lui","ygugi", 0};
    printf("result is %d",ft_count_if(array,&ft_str_is_alpha));
    
    return 0;
}
