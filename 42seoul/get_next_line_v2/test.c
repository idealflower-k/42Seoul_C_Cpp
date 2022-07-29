#include <unistd.h> // open, read
#include <stdio.h> // printf
#include <fcntl.h> // read dhqtusdls O_RDONLY 등

int main(void)
{
	int fd;
	char *temp;
	int i;

	i = 0;

	fd = open("test.txt", O_RDONLY);
	read(fd, temp, 42);
	printf("%s", temp);
	i = read(fd, temp, 42);
	if (i == 0)
		printf("eof\n");
	printf("%s", temp);
	close(fd);
	return (0);
}