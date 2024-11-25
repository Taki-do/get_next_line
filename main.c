#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		i;
    int 	fd;
	char	*line;

	i = 0;
    fd = open("get_next_line.c", O_RDONLY);
	while (i < 21)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
}