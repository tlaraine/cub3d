/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:24:00 by tlaraine          #+#    #+#             */
/*   Updated: 2021/01/12 00:46:20 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setstrs(char **line, char **rem)
{
	char	*ptr;
	char	*tmp;

	ptr = ft_strchr(*rem, '\n');
	*ptr = 0;
	*line = ft_strdup(*rem);
	tmp = ft_strdup(++ptr);
	free(*rem);
	*rem = tmp;
}

int		ft_chkstrs(int out, char **line, char **rem)
{
	if (!out && !*rem)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (out < 0)
	{
		if (*rem)
		{
			free(*rem);
			*rem = 0;
		}
		return (-1);
	}
	else if (ft_strchr(*rem, '\n'))
		ft_setstrs(line, rem);
	else
	{
		*line = ft_strdup(*rem);
		free(*rem);
		*rem = 0;
		return (0);
	}
	return (1);
}

int		get_line(int fd, char **rem, char **line)
{
	char	*buf;
	char	*tmp;
	int		out;

	if (BUFFER_SIZE <= 0 || !(buf = (char*)malloc(BUFFER_SIZE + 1))
	|| fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	while ((out = read(fd, buf, BUFFER_SIZE)))
	{
		buf[out] = 0;
		if (!*rem)
			*rem = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*rem, buf);
			free(*rem);
			*rem = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	buf = 0;
	return (ft_chkstrs(out, line, rem));
}

int		get_next_line(int fd, char **line)
{
	static char	*m_rem[4096];

	if (m_rem[fd])
		return (get_line(fd, &m_rem[fd], line));
	else
	{
		m_rem[fd] = 0;
		return (get_line(fd, &m_rem[fd], line));
	}
}
