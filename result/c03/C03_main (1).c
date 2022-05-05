/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joushin <joushin@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:11:57 by joushin           #+#    #+#             */
/*   Updated: 2022/04/21 08:59:40 by joushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex00/ft_strcmp.c"
#include"ex01/ft_strncmp.c"
#include"ex02/ft_strcat.c"
#include"ex03/ft_strncat.c"
#include"ex04/ft_strstr.c"
#include"ex05/ft_strlcat.c"

int main()
{
	{
		printf("\n----------------------ex00----------------------------\n");
		char Arr1[10] ="abcdefgh";
		char Arr2[10] = "abedeFgh";
		char arr1[10] ="abcdefgh";
		char arr2[10] = "abedeFgh";
		int a = strcmp(Arr1, Arr2);
		int b = ft_strcmp(arr1, arr2);
		printf("result :%s  %d\n",Arr1 ,a);
		printf("your answer :%s   %d\n",arr1,b);
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex01----------------------------\n");
		char Arr1[10] ="abcdefgh";
		char Arr2[10] = "abedeFgh";
		char arr1[10] ="abcdefgh";
		char arr2[10] = "abedeFgh";
		int size =6;
		int a = strncmp(Arr1, Arr2,size);
		int b = ft_strncmp(arr1, arr2,size);
		printf("result : %s  %d\n",Arr1,a);
		printf("your answer :%s %d\n",arr1,b);
	}
	{
		printf("\n----------------------ex02----------------------------\n");
	
		char Arr1[100] ="abcdefgh";
		char Arr2[100] = "abedeFgh";
		char arr1[100] ="abcdefgh";
		char arr2[100] = "abedeFgh";
		char *a = strcat(Arr1, Arr2);
		char *b = ft_strcat(arr1, arr2);
		printf("result :%s \n",a);
		printf("your answer :%s \n",b);
	}
	{
		printf("\n----------------------ex03----------------------------\n");
		char Arr1[100] ="abcdefgh";
		char Arr2[100] = "abedeFgh";
		char arr1[100] ="abcdefgh";
		char arr2[100] = "abedeFgh";
		int size =6;
		char *a = strncat(Arr1, Arr2,size);
		char *b = ft_strncat(arr1, arr2,size);
		printf("result : %s \n",a);
		printf("your answer :%s\n",b);
	}
	{
		printf("\n----------------------ex04----------------------------\n");
		char arr[100] = "i am joushin";

		printf("\n\n<function result>\n\n");
		printf("%s\n",strstr(arr, "joushin"));
		printf("%s\n",strstr(arr, "koushin"));
		printf("\n\n<your result>\n\n");
		printf("%s\n",ft_strstr(arr, "joushin"));
		printf("%s\n",ft_strstr(arr, "koushin"));

	}
	{
		printf("\n----------------------ex05----------------------------\n");
		char dest[100] = "hi my name is joushin";//21
		char src[100] = "hello world";//11
		char _dest[100] = "hi my name is joushin";//21
		char _src[100] = "hello world";//11
		char dest2[100] = "hi my name is joushin";
		char src2[100] = "hello world";
		char _dest2[100] = "hi my name is joushin";
		char _src2[100] = "hello world";
		char dest3[100] = "hi my name is joushin";
		char src3[100] = "hello world";
		char _dest3[100] = "hi my name is joushin";
		char _src3[100] = "hello world";
		int	size = 0;//size < 1
		int size2 = 2;// size < destlen
		int size3 = 30;// size > destlen
		printf("\n\n<function result>\n\n");
		int result = strlcat(dest,src,size);
		printf("%s, %d",dest,result);
		printf("\n\n<your result>\n\n");
		result = ft_strlcat(_dest, _src,size);
		printf("%s,%d",_dest, result);
		printf("\n\n<function result>\n\n");
		result = strlcat(dest2,src2,size2);
		printf("%s, %d",dest2,result);
		printf("\n\n<your result>\n\n");
		result = ft_strlcat(_dest2, _src2,size2);
		printf("%s,%d",_dest2, result);
		printf("\n\n<function result>\n\n");
		result = strlcat(dest3,src3,size3);
		printf("%s, %d",dest3,result);
		printf("\n\n<your result>\n\n");
		result = ft_strlcat(_dest3, _src3,size3);
		printf("%s,%d",_dest3, result);
	}
}
