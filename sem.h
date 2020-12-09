#include <unistd.h>
#include <sys/sem.h>

//信号量的下标，需要两个信号量，这里写固定了
#define SEM_A 0
#define SEM_B 1
#define SEM_C 2

union semun
{
    int val;
};

void sem_init();
void sem_p(int num); //参数是代表操作哪个信号量
void sem_v(int num);
void sem_destroy();
