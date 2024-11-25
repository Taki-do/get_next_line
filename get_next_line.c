/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:54:35 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/25 13:26:31 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_list			*head;
	static char		buf[BUFFER_SIZE];
	
	//if il n'y a pas de \n dans le buffer
	read(fd, buf, BUFFER_SIZE);
	while ()
	head = ft_lstnew((void *)buf);
	
}
