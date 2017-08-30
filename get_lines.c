/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 04:02:24 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 04:02:35 by nocardoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <fcntl.h>
#include <unistd.h>

int		ft_get_line(int fd, char **line, int buf_size)
{
	char	c;
	int		len;
	char	*buf;

	len = 0;
	buf = malloc(buf_size * sizeof(char));
	while (read(fd, &c, 1) && c != '\n')
	{
		buf[len++] = c;
		if (len >= buf_size)
			buf = ft_realloc(buf, (buf_size *= 2));
	}
	buf[len] = '\0';
	*line = buf;
	return (len);
}

int		ft_get_line_n(int fd, char **line, int buf_size)
{
	char	*buf;
	char	c;
	int		ret;
	int		chunk;
	int		total;

	chunk = buf_size;
	total = 0;
	if (!fd)
		chunk = 4096;
	buf = malloc((buf_size + 1) * sizeof(char));
	while ((ret = read(fd, (buf + total), buf_size - total)) &&
		(total += ret) != buf_size)
		;
	if (ret && read(fd, &c, 1) && c == '\n')
	{
		buf[buf_size + 1] = '\0';
		*line = buf;
		return (buf_size);
	}
	return (0);
}

int		ft_get_line_buff(int fd, char **buf, int buf_size)
{
	char	c;
	int		ret;
	int		chunk;
	int		total;

	chunk = buf_size;
	total = 0;
	if (!fd)
		chunk = 4096;
	while ((ret = read(fd, (buf + total), buf_size - total)) &&
		(total += ret) != buf_size)
		;
	if (ret && read(fd, &c, 1) && c == '\n')
	{
		buf[buf_size + 1] = '\0';
		*line = buf;
		return (buf_size);
	}
	return (0);
}

int		index_of(char c, char *str)
{
	int	i;

	i = -1;
	while (str[i])
	{
		if (str[i++] == c)
			return (i - 1);
	}
	return (-1);
}