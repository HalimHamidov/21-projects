/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:36:05 by apearl            #+#    #+#             */
/*   Updated: 2019/09/14 17:40:15 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;
    
    i = 0;
	while (str[i])
        i++;
    return (i);
}

int main(void)
{
	char a[] = {""};
	char b[] = {" "};
	char c[] = {"Uw5"};
	char d[] = {"0x8avTzsjiRH"};
	char e[] = {"dZi8"};
	char f[] = {"TVO zNDgAJ3 RnQy4gbvXKcOUr cdAQZIGEM782Y xCBv kzyZgE07"};
	char g[] = {"o9p7FK5lQX RZlMJ fqTE9sXjyL 8Owc pgxMn6EGPo P9Np"};
	char h[] = {"aASuflB52Zjt0d 0fwqL F1WkdIg3lPR GMQyB 4b8ADHwVjzBs FVZHwnj canRNIo YNGZxWTC2fpJRXV6 CsbzARuL TLrYd pD8i6SsknxHfAt9Q AIpKZjThCLlYbF LR75yf6FI Ksmpq4MC3A0FxVUG OoVNWUvx3 JAK"};
	
	printf("%d\n", ft_strlen(a));
	printf("%d\n", ft_strlen(b));
	printf("%d\n", ft_strlen(c));
	printf("%d\n", ft_strlen(d));
	printf("%d\n", ft_strlen(e));
	printf("%d\n", ft_strlen(f));
	printf("%d\n", ft_strlen(g));
	printf("%d\n", ft_strlen(h));
	return (0);
}
