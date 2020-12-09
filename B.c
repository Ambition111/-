#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "sem.h"

int main()
{
    sem_init();  //初始化信号量
    
    int i = 5;
    while (i)
    {
        sem_p(SEM_B);
        printf("B");
        fflush(stdout);
        sleep(1);
        sem_v(SEM_C);

        sleep(1);
        --i;
    }
    exit(0);
}

