/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:00:58 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/19 13:39:20 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_init_square_size(t_item **items)
{
	int		size;

	size = 0;
	while (items[size])
		size++;
	return (ft_sqrt(size * 4));
}

void	clear_square(t_field *field)
{
	int	i;
	int	j;

	i = 0;
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
			field->square[i][j++] = '.';
		i++;
	}
}

void	print_answer(t_field *field)
{
	int i;
	int j;

	i = 0;
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
		{
			ft_putchar(field->square[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		try_accommodate(t_item **items, int square_size)
{
	t_field *field;
	int		i;

	i = 0;
	field = (t_field *)malloc(sizeof(t_field));
	field->square = (char **)malloc(square_size * sizeof(char *));
	while (i < square_size)
		field->square[i++] = (char *)malloc(square_size * sizeof(char));
	field->size = square_size;
	clear_square(field);
	if (fill_square(field, items, 0))
	{
		print_answer(field);
		free_field(field);
		return (1);
	}
	free_field(field);
	return (0);
}

int		process_algorithm(t_item **items)
{
	int		square_size;

	square_size = get_init_square_size(items);
	while (!try_accommodate(items, square_size))
		square_size++;
	return (1);
}
