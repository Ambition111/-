#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>

#define ROOT 0
#define PATH "/home/stu/study/mycode/day08_mybash/mybin/"

void printf_info()
{
    //获取用户uid
    int id = getuid();

    //设置提示符的身份信息
    char* s = "$";
    if (id == ROOT)
        s = "#";
    
    //使用uid获取用户信息（包含了用户名字）
    struct passwd *ptr = getpwuid(id);//root:x:0:0:root:/root:/bin/bash
    if (ptr == NULL)
    {
        printf("mybash$ ");
        fflush(stdout);
        return;
    }

    //获取主机名
    char host[128] = {0};
    int res = gethostname(host, 128);//获取主机名，成功返回0，失败返回-1
    if (res == -1)
    {
        printf("mybash$ ");
        fflush(stdout);
        return;
    }
    
    //获取当前路径
    char dirpath[256] = {0};
    getcwd(dirpath, 256);
    
    printf("[%s@%s %s]%s ",ptr->pw_name, host, dirpath, s);
    fflush(stdout);
        
}



int main()
{
    while (1)
    {
        //printf("[stu@localhost ~$] ");   //提示符
        //fflush(stdout);
        
        printf_info();//打印带有用户信息主机主机信息的提示符

        char buff[128] = {0}; //存放命令的名字
        fgets(buff, 128, stdin); //fgets得到的字符串后有'\n'
        buff[strlen(buff) - 1] = '\0'; //减1是因为有'\n'

        char* myargv[10] = {0}; //存放指向每个命令及参数的指针
        int i = 0;
        char *s = strtok(buff, " "); //字符串分割//cp a.c b.c
        while (s != NULL)
        {
            myargv[i++] = s;//[0]="cp" [1]="a.c" [2]="b.c"
            s = strtok(NULL, " ");//传NULL会沿着之前的位置继续分割
        }

        //不输命令时可以直接回车
        if (myargv[0] == NULL)
        {
            continue;
        }

        //输入exit退出mybash
        if (strcmp(myargv[0], "exit") == 0)
        {
            break;
        }
        
        else if (strcmp(myargv[0], "cd") == 0)
        {
            if (myargv[1] != NULL)
            {
                chdir(myargv[1]);//chdir是系统调用，可以浏览目录
                continue;
            }
        }

        pid_t pid = fork();
        if (pid == -1)
            continue;

        if (pid == 0)
        {
            /*execlp不需要给出要替换的命令的全路径，只需要给出命令名字
              因为有p PATH环境变量自动拼接*/
            //execlp(buff, buff, (char*)0);//不带参数 //bin/pwd "pwd" NULL
            //execvp(myargv[0], myargv);//带参数

            char path[256] = {0};//记录自己实现的命令的路径
            
            //如果用户输入绝对路径或相对路径，则不拼接
            if (strncmp(myargv[0], "/", 1) != 0 && strncmp(myargv[0], "./", 2) != 0)
            {
                strcpy(path, PATH);
            }
            strcat(path, myargv[0]);//将ls或pwd等命令拼接到path后
            execv(path, myargv);
            perror("exec err"); //打印出错误信息 
            exit(0);
        }
        wait(NULL); //父进程等待子进程先结束，避免僵死进程
    }

    exit(0);
}







