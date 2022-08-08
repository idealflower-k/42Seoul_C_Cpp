#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd;
	char *str;

	fd = open("test.txt", 0);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
		close(fd);
		free(str);
	}
	return (0);
}
