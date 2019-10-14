/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:50:17 by apearl            #+#    #+#             */
/*   Updated: 2019/10/09 02:45:51 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		strlinecpy(char **str, char **line)
{
	int			i;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if (!(*line = ft_strsub(*str, 0, i)))
		return (-1);
	if ((*str)[i] != '\0')
		*str = ft_strcpy(*str, (*str + i) + 1);
	else
		ft_strdel(str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			bwr;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*str[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!line || (!str[fd] && !(str[fd] = ft_strnew(0))))
		return (-1);
	while ((bwr = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bwr] = '\0';
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(str[fd], buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	if (bwr <= 0 && !ft_strlen(str[fd]))
		return (bwr);
	return (strlinecpy(&str[fd], line));
}
