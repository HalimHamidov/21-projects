/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:47:23 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 22:56:20 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		good_symbols(char **s)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (s[i][j] == '#')
				res++;
			else if (s[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (res == 4);
}

void	find_first(int *i, int *j, char **s)
{
	*i = 0;
	while (*i < 4)
	{
		*j = 0;
		while (*j < 4)
		{
			if (s[*i][*j] == '#')
				return ;
			*j = *j + 1;
		}
		*i = *i + 1;
	}
}

int		get_count(char **s, int i, int j)
{
	int	lr;
	int	ud;

	if (i < 0 || i >= 4 || j < 0 || j >= 4)
		return (0);
	if (s[i][j] == '.' || s[i][j] == '+')
		return (0);
	s[i][j] = '+';
	lr = get_count(s, i + 1, j) + get_count(s, i - 1, j);
	ud = get_count(s, i, j + 1) + get_count(s, i, j - 1);
	return (lr + ud + 1);
}

int		good_tetramino(char **s)
{
	int	i;
	int	j;

	find_first(&i, &j, s);
	return (get_count(s, i, j) == 4);
}

int		correct_block(char **s)
{
	return (good_symbols(s) && good_tetramino(s));
}
