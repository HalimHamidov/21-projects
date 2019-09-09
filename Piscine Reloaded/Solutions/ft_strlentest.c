/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:16:27 by apearl            #+#    #+#             */
/*   Updated: 2019/09/09 18:30:15 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main (void)
{
	printf("%d", ft_strlen("Halim"));
	return(0);
}

/*
 int main(void)
 {
 printf("%lu", strlen("Halim"));
 return (0);
 }
*/

