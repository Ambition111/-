#include "sem.h"

int semid = -1;

void sem_init()
{
    //2代表2个信号量,IPC_CREAT|IPC_EXCL代表全新创建信号量
    semid = semget((key_t)1234, 3, IPC_CREAT|IPC_EXCL|0600);
    if (semid == -1)
    {
        semid = semget((key_t)1234, 3, 0600);
        if (semid == -1)
        {
            perror("semget err");
            return;
        }
    }

    else    //获取信号量成功
    {
        int arr[3] = {1, 0, 0};
        union semun a;
        int i;
        for (i = 0; i < 3; ++i)
        {
            a.val = arr[i];  // 为两个信号量赋初值
            if (semctl(semid, i, SETVAL, a) == -1)
            {
                perror("semctl setval err");
            }
        }
    }
}

void sem_p(int num)
{
    struct sembuf buf;
    buf.sem_num = num;
    buf.sem_op = -1;    //p
    buf.sem_flg = SEM_UNDO;

    if (semop(semid, &buf, 1) == -1)
    {
        perror("semop err p");
    }
}

void sem_v(int num)
{
    struct sembuf buf;
    buf.sem_num = num;
    buf.sem_op = 1;    //v
    buf.sem_flg = SEM_UNDO;

    if (semop(semid, &buf, 1) == -1)
    {
        perror("semop err v");
    }
}

void sem_destroy()
{
    if (semctl(semid, 0, IPC_RMID) == -1)
    {
        perror("semctl destroy err");
    }
}

