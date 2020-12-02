#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


//  b.c 负责从管道文件中读取数据

int main()
{
    int fd = open("./fifo", O_RDONLY);
    assert(fd != -1);
    printf("open fifo read\n");

    while (1)
    {
        char buff[128] = {0};
        int res = read(fd, buff, 127);//管道被对方关闭了

        if (res == 0)
        {
            break;
        }
        printf("buff=%s\n", buff);
    }
    close(fd);
    exit(0);
}
