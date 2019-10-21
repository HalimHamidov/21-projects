/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:42:17 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/19 15:11:20 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			has_lb(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int			found_and_erase(char **s, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '\n')
			break ;
		i++;
	}
	*line = ft_strsub(*s, 0, i);
	tmp = *s;
	*s = ft_strsub(*s, i + 1, ft_strlen(*s) - i);
	free(tmp);
	return (1);
}

void		strjoin_with_clear(char **s, char *buff)
{
	char	*tmp;

	tmp = *s;
	*s = ft_strjoin(*s, buff);
	free(tmp);
}

int			kill_data(char *s)
{
	free(s);
	return (0);
}

int			get_next_line(const int fd, char **line, int fin)
{
	static char *s[MAX_FD_COUNT];
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (fin)
		return (kill_data(s[fd]));
	if (fd < 0 || !line)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	if (has_lb(s[fd]))
		return (found_and_erase(&s[fd], line));
	while (!has_lb(s[fd]))
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) <= 0)
			break ;
		buffer[ret] = 0;
		strjoin_with_clear(&s[fd], buffer);
	}
	if (ret < 0)
		return (-1);
	if (has_lb(s[fd]))
		return (found_and_erase(&s[fd], line));
	*line = s[fd];
	return (!ret && (!s[fd] || !*s[fd]) ? !!(*line = 0) : 1);
}
