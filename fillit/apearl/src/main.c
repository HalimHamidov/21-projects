/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/19 15:52:04 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_usage(char *exec_name)
{
	ft_putstr(exec_name);
	ft_putstr(": missing file with tetraminos\n");
	ft_putstr("Try '");
	ft_putstr(exec_name);
	ft_putstr(" file_with_tetraminos'\n");
}

void	show_error(void)
{
	ft_putstr("error\n");
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		show_usage(argv[0]);
		return (1);
	}
	if (!fillit(argv[1]))
		show_error();
	return (0);
}
