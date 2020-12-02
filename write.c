#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

// a.c 负责对管道文件进行写入

int main()
{
    int fd = open("./fifo", O_WRONLY);//a.c b.c必须都被打开，只打开一个系统会阻塞掉
    assert(fd != -1);
    printf("open fifo\n");

    while (1)
    {
        char buff[128] = {0};
        fgets(buff, 128, stdin);
        if (strncmp(buff, "end", 3) == 0)
        {
            break;
        }
        write(fd, buff, strlen(buff));
    }
    close(fd);
    exit(0);
}
