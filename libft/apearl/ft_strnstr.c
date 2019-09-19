/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 07:01:49 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 07:01:53 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;
	size_t	n;

	i = 0;
	j = 0;
	s1 = (char*)hay;
	s2 = (char*)need;
	n = ft_strlen(s2);
	if (s2[j] == 0)
		return (&s1[i]);
	while (s1[i] != 0 && n <= len--)
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			if (s2[j + 1] == '\0')
				return (&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
