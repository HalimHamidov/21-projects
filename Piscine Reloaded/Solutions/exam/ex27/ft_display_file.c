/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 07:11:48 by apearl            #+#    #+#             */
/*   Updated: 2019/09/15 07:16:06 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display(char *filename)
{
	int	file;
	char	character;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return ;
	while (read(file, &character, 1))
		write(1, &character, 1);
	close(file);
}

int main(int ac, char *av[])
{
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display(av[1]);
	return (0);
}
