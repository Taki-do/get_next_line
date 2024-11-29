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

#include "get_next_line_bonus.h"

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

char	*ft_read(int fd, char **buf, char *line)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf[fd], BUFFER_SIZE);
		if (rd == -1)
			return (ft_z(buf[fd], BUFFER_SIZE + 1), free(buf[fd]),
				buf[fd] = NULL, free(line), line = NULL, NULL);
		buf[fd][rd] = '\0';
		if (ft_is_ln(buf[fd]))
			return (ft_return_ln(buf[fd], line));
		line = ft_strjoin(line, buf[fd], ft_strlen(buf[fd]));
	}
	if (rd == 0 && !line[0])
		return (free(buf[fd]), buf[fd] = NULL, free(line),
			line = NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buf[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf[fd])
			return (NULL);
		buf[fd][0] = '\0';
	}
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (buf[fd][0])
	{
		if (ft_is_ln(buf[fd]))
			return (ft_return_ln(buf[fd], line));
		line = ft_strjoin(line, buf[fd], ft_strlen(buf[fd]));
	}
	return (ft_read(fd, buf, line));
}
