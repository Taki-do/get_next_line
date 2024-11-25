/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:54:35 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/25 17:19:26 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
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
	int		s_len;
	char	*dup;

	s_len = ft_strlen(s);
	dup = (char *)malloc((s_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, s);
	return (dup);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			dest_cpy[i] = src_cpy[i];
	}
	else if (dest > src)
	{
		i = n + 1;
		while (--i > 0)
			dest_cpy[i - 1] = src_cpy[i - 1];
	}
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (i == n)
		return (dest);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	int				i;
	int				rd;
	char			*line;
	static char		buf[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0) //peut del read
		return (NULL);
	rd = 1;
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (buf[0])
	{
		if (buf[0] == '\n')
		{
    		line = ft_strjoin(line, "\n", 1);
    		ft_memmove(buf, buf + 1, BUFFER_SIZE - 1);
    		return (line);
		}
		if (ft_is_ln(buf))
		{
			i = 0;
			while (buf[i] != '\n' && buf[i])
				i++;
			line = ft_strjoin(line, buf, i + 1);
			ft_memmove(buf, buf + i + 1, BUFFER_SIZE - i);
			return (line);
		}
		line = ft_strjoin(line, buf, ft_strlen(buf));
	}
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (ft_bzero(buf, BUFFER_SIZE + 1), free(line), line = NULL, NULL);
		if (rd >= 0)
			buf[rd] = '\0';
		if (ft_is_ln(buf))
		{
			i = 0;
			while (buf[i] != '\n' && buf[i])
				i++;
			line = ft_strjoin(line, buf, i + 1);
			ft_memmove(buf, buf + i + 1, BUFFER_SIZE - i);
			return (line);
		}
		line = ft_strjoin(line, buf, ft_strlen(buf));
	}
	if (rd == 0 && !line[0])
		return (free(line), line = NULL, NULL);
	return (line);
}
