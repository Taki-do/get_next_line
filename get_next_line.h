/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:53:15 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/25 16:57:56 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

//# define BUFFER_SIZE 89

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strjoin(char *s1, char const *s2, int n);

int		ft_is_ln(char *s);
size_t	ft_strlen(char const *s);

#endif