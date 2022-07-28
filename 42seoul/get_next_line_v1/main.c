
#include <unistd.h> // open, read
#include <stdio.h> // printf
#include <fcntl.h> // read dhqtusdls O_RDONLY 등

int main(void)
{
	int fd;
	char *temp;

	fd = open("test1.txt", O_RDONLY);
	temp = get_next_line(fd);

	printf("%s", temp);
}