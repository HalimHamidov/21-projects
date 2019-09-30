/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 06:35:45 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 06:46:17 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1)))
		return (NULL);
	ft_strcpy(str, s);
	while (str[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
