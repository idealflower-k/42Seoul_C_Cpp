#include <stdio.h>
int main()
{
	const int chunk = 29; // <= input
	int num = 499;

	for (int i = 0; chunk * (i + 1) < num; i++)
	{
		for (int j = 0; j < chunk; j += 2)
		{
			const int a = num - chunk * i - j;
			printf("%d ", a);
		}
		for (int j = chunk%2 == 0 ? 1 : 2; j < chunk; j += 2)
		{
			const int a = num - chunk * (i + 1) + j;
			printf("%d ", a);
		}
		if (chunk * (i + 2) >= num)
		{
			num = num - chunk * (i + 1);
		}
	}
	int endpoint;
	for (int i = 0 ;i <= num; i += 2)
	{
		printf("%d ", num - i);
		if(num - i == 1)
			endpoint = 0;
		if(num - i == 0)
			endpoint = 1;
	}
	for (int i = 0 ;i + endpoint < num; i += 2)
	{
		printf("%d ", i + endpoint);
	}
	return 0;
}