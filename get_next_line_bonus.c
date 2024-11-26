/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:44:31 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/26 15:44:34 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_z(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*dup;

	i = 0;
	s_len = ft_strlen(s);
	dup = (char *)malloc((s_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_return_ln(char buf[BUFFER_SIZE + 1], char *line)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	line = ft_strjoin(line, buf, i + 1);
	ft_strncpy(buf, buf + i + 1, BUFFER_SIZE - i);
	return (line);
}

char	*ft_read(int fd, char buf[BUFFER_SIZE + 1], char *line)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (ft_z(buf, BUFFER_SIZE + 1), free(line), line = NULL, NULL);
		buf[rd] = '\0';
		if (ft_is_ln(buf))
			return (ft_return_ln(buf, line));
		line = ft_strjoin(line, buf, ft_strlen(buf));
	}
	if (rd == 0 && !line[0])
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[1024][BUFFER_SIZE + 1];

	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (buf[fd][0])
	{
		if (ft_is_ln(buf[fd]))
			return (ft_return_ln(buf[fd], line));
		line = ft_strjoin(line, buf[fd], ft_strlen(buf[fd]));
	}
	return (ft_read(fd, buf[fd], line));
}
