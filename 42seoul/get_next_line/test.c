#include <unistd.h> // open, read
#include <stdio.h> // printf
#include <fcntl.h> // read dhqtusdls O_RDONLY 등
#define BUF_SIZE 10

int main(void)
{
	static char txt_str[BUF_SIZE];
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	
	printf("test1.txt fd value : %d\n", fd1);
	printf("test2.txt fd value : %d\n", fd2);

	char buff1[BUF_SIZE + 1];
	char buff2[BUF_SIZE + 1];
	int n1 = read(fd1, buff1, BUF_SIZE);
	buff1[n1] = 0;
	puts(buff1);
	int n2 = read(fd2, buff2, BUF_SIZE);
	buff2[n2] = 0;
	puts(buff2);
	printf("test1.txt n1 value : %d\n", n1);
	printf("test2.txt n1 value : %d\n", n2);
	int i = 0;
	while (buff1[i] != '\n')
	{
		txt_str[i] = buff1[i];
		i++;
	}
	printf("buff1's text : %s\n", txt_str);
	close(fd1);
	close(fd2);

	return (0);
}