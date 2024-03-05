#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"ex00/ft_strdup.c"
#include"ex01/ft_range.c"
#include"ex02/ft_ultimate_range.c"
#include"ex03/ft_strjoin.c"
#include"ex04/ft_convert_base.c"
#include"ex04/ft_convert_base2.c"
#include"ex05/ft_split.c"
int main()
{
	{
		printf("\n----------------------ex00----------------------------\n");
		char arr[10] = "abcdef";
		char *src;
		src = ft_strdup(arr);
		printf("%s",src);
		
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex01----------------------------\n");
		long long	min = -5;
		long long	max = 2;
		int *arr = ft_range(min, max);
		if (!arr)
		{
			printf("can't malloc\n");
			return (0);
		}
		printf("min : %lld\nmax : %lld\n\n\n", min, max);
		for (int i = 0; i < max - min; i++)
		{
			printf("%d\n",arr[i]);
		}
		free(arr);
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex02----------------------------\n");
		int min = -3;
		int	max = 6;
		int *arr;
		printf("min :%d  max: %d\n\n",min, max);
		int result =ft_ultimate_range(&arr, min, max);
		printf("result:::::: len :%d \n\n\n\n",result);
		if (result <= 0)
		{
			printf("ex02 error check is ok\n");
		}
		else
		{
			for (int i = 0; i < result; i++)
			{
				printf("arr[%d] : %d\n", i,arr[i]);
			}
			free(arr);
		}
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex03----------------------------\n");
		char *arr[10];
		arr[0] ="hi my name is";
		arr[1] = "joushin";
		arr[2] ="slim sady";
		arr[3] = "doctor";
		arr[4] = "dere";
		char *sep = "===seperate===";
		char *result = ft_strjoin(5,arr, sep);
		printf("result ::::  %s \n\n\n\n",result);
		free(result);

	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex04----------------------------\n");
		char basefrom[100] = "0123456789";
		char baseto[100] = "0123456789";
		char input[100] = "      -123450";
		printf("basefrom : %s\nlen : %lu \n input num : %s baseto: %s \n\n\n",basefrom ,strlen(basefrom),input, baseto);
		char *result = ft_convert_base(input, basefrom, baseto);
		printf("result::: %s\n\n\n",result);
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex05----------------------------\n");
		char str[1000] ="          hi my name is joushin I don't know this problem";
		char sep[100] = " ";
		char **result = ft_split(str, sep);
		for (int i = 0; result[i] != 0; i++)
			printf("%d :::::%s\n\n",i,result[i]);

	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
}
