#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	i;
    int fd;

	i = 0;
    fd = open("get_next_line.c", O_RDONLY);
	while (i < 20)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}