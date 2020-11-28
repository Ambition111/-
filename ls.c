#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>


int main()
{
    char dir_buff[512] = {0};
    getcwd(dir_buff, 512);//获取当前位置
    
    DIR *p = opendir(dir_buff);//打开目录流
    if (p == NULL)
    {
        perror("opendir err");
        exit(1);
    }

    struct dirent *s = NULL;
    while ((s = readdir(p)) != NULL)//读取目录流中的信息，每条信息(文件结构体)对应一个文件
    {
        if (strncmp(s->d_name, ".", 1) != 0)//不打印以.开头的隐藏文件
        {
            printf("%s   ", s->d_name);//打印文件名
        }
    }
    printf("\n");

    closedir(p);//关闭目录流
    exit(0);
}
