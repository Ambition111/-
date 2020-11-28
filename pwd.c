#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


int main()
{
    char dir_buff[512] = {0};
    getcwd(dir_buff, 512);
    printf("%s\n", dir_buff);


    exit(0);
}
