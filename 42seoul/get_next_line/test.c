#include <stdio.h>
#include <memory.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char file_buff[100];
	int i;

	fp = fopen("test.txt", "w");

	if (fp == NULL)
		printf("fail\n");
	else
		printf("sucess\n");

	for (i = 1; i <= 5; i++)
	{
		printf("파일 내용 입력 (%d번째 라인)\n", i);
		memset(file_buff, 0, sizeof(file_buff));
		scanf("%s", file_buff);
		file_buff[strlen(file_buff)] = '\n';

		fputs(file_buff, fp);
	}
	fclose(fp);

	fp = fopen("test.txt", "r");
	
	if (fp == NULL)
		printf("fail\n");
	else
		printf("sucess\n");

	while (fgets(file_buff, sizeof(file_buff), fp) != NULL)
	{
		printf("%s", file_buff);
		memset(file_buff, 0, sizeof(file_buff));
	}
	fclose(fp);

	return (0);
}