#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


int main()
{
	pit_t pid = fork();
	
	int i = 0;
	
	if (pid == 0)//�ӽ���pidΪ0 
	{
		for (; i < 5; i++)
		{
			printf("child\n");
			sleep(1);//ÿ��ӡһ��˯��һ���� 
		}		
	} 
	else//������ 
	{
		for (; i < 5; i++)
		{
			printf("child\n");
			sleep(1);//ÿ��ӡһ��˯��һ���� 
		}
	} 

	exit(0);
} 
/*
	������Ϊ�����������ӽ��̲������У�ÿһ��ͬʱ���parent��child�� 
*/ 

 
