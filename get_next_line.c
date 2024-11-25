/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:54:35 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/25 16:32:07 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		buf[BUFFER_SIZE];
	
	i = 0;
	line = "\0";
	if (buf[0] == '\n')
		line = ft_strjoin(line, buf, ft_strlen(buf));
	while (1) //Attention comparaison
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		if (rd == 0)
			return (line);
		if (ft_is_ln(buf))
		{
			while (buf[i] != '\n' && buf[i])
				i++;
			line = ft_strjoin(line, buf, i);
			ft_strcpy(buf, buf + i);
			return (line);
		}
		line = ft_strjoin(line, buf, ft_strlen(buf));
	}
	return (line);
}
