/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:54:35 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/14 16:28:42 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	//static for cursor.
	//if '\n' encounter stop and return line value (with \n if present).
	//End of file || Error return NULL.
	//Can read stdin.
	
	int			rd;
	int			size;
	char		buf[BUFFER_SIZE]; //unsigned char for binary
	static int	cursor;
	
	cursor = 0;
	size = 0;
	if(read(fd, buf, BUFFER_SIZE) == -1)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	while (buf[cursor])
	{
		
	}
}