#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


int main()
{
	pit_t pid = fork();
	
	int i = 0;
	
	if (pid == 0)//子进程pid为0 
	{
		for (; i < 5; i++)
		{
			printf("child\n");
			sleep(1);//每打印一次睡眠一秒钟 
		}		
	} 
	else//父进程 
	{
		for (; i < 5; i++)
		{
			printf("child\n");
			sleep(1);//每打印一次睡眠一秒钟 
		}
	} 

	exit(0);
} 
/*
	输出结果为：父进程与子进程并发运行，每一秒同时输出parent和child。 
*/ 

 
