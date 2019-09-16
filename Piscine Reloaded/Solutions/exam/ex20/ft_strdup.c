/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 00:37:08 by apearl            #+#    #+#             */
/*   Updated: 2019/09/15 00:42:04 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char *ret;
	int i;

	i = 0;
//	if (!(ret = (char *)malloc(sizeof(*ret) * ft_strlen(src) + 1)))
//		return (NULL);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
int main ()
{
    char *str= "Salom aleykum Hacker";
    char *copy;
    copy = ft_strdup(str);
    printf("%s", copy);
    return 0;
}


