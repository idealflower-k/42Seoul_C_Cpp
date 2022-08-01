#include "get_next_line.h"
#include <unistd.h> // open, read
#include <stdio.h> // printf
#include <fcntl.h> // read dhqtusdls O_RDONLY 등

int main(void)
{
	int fd1;
	// int	fd2;
	char *line1;
	// char *line2;

	fd1 = open("test1.txt", O_RDONLY);
	// fd2 = open("test2.txt", O_RDONLY);
	printf("fd1 : %d\n", fd1);
	// printf("fd2 : %d\n", fd2);

	line1 = get_next_line(fd1);
	printf("%s", line1);
	// line2 = get_next_line(fd2);
	// printf("%s", line2);

	free(line1);
	// free(line2);

	line1 = get_next_line(fd1);
	printf("%s", line1);
	// line2 = get_next_line(fd2);
	// printf("%s", line2);

	free(line1);
	// free(line2);

	close(fd1);
	// close(fd2);
	
	return (0);
}