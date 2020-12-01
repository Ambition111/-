/*
	有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数）
	凡是报到3的人退出圈子，问最后留下的是原来第几号的那位。 
*/
 
int JosephProblem(int n)//约瑟夫环
{
    int *arr = (int *)malloc(n*sizeof(int));//相当于定义了arr[n];
    int i;
    for(i = 0;i < n;i++)
    {
        arr[i] = 1; //先将所有人标记为1
    }
    int count = n;  //还在参与游戏的人数
    int tmp = 0;     //报数器
    i = 0;
    while(count > 1)    //当剩一个人的时候退出循环
    {
        if(arr[i] == 1) //如果还在参与游戏
        {
            tmp++;
            if(tmp == 3)
            {
                arr[i] = 0;     //报到3退出游戏
                tmp = 0;      //计数器清零
                count--;       //人数减1
            }
        }
        i = (i+1)%n;    //环形问题
    }
    for(i = 0;i < n;i++)
    {
        if(arr[i] == 1) //找到最后还被标记为1的人既是赢家
        {
            break;
        }
    }
    free(arr);
    return i+1; //数组元素下标从0开始而第一个人从1开始报数
}

