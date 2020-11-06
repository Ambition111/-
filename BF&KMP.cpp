#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�ַ�������

//str ������sub �Ӵ���pos �����ʼλ��
int BF(const char *str,const char *sub,int pos)//(BF�㷨) ��ͨ���ҷ���O(n*m) nΪ�������� mΪ�Ӵ����ȡ�
{
    int i = pos;
    int j = 0;
    int lenstr = strlen(str);
    int lensub = strlen(sub);
    if(i < 0 || i >= lenstr)//��겻��������֮ǰ��֮��
    {
        return -1;//û�ҵ�
    }
    while(i < lenstr && j < lensub)
    {
        if(str[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;//i���˵��ղŵ�λ�õ���һ��
            j = 0;
        }
    }
    if(j == lensub)//�ҵ���
    {
        return i-j;
    }
    else//û�ҵ�
    {
        return -1;
    }    
}
//***************************************************************************************

void GetNext(const char *sub,int *next)//j���˵�j==kʱ,�������ǰ���ַ�һ��,�����ж����Ч�ıȽ�,������Ҫ�Ľ�Ϊnextval������kֵ,�������ǰ���ַ�һ��,��k��Ϊ-1
{
    int len = strlen(sub);
    next[0] = -1;//�����������һ��Ԫ��ǰʱ��posǰû���ַ����Ͳ�������������ͬ���ַ��������Խ�next[0]��Ϊ-1
    next[1] = 0;//����������ڶ���Ԫ��ǰʱ��posǰֻ��һ���ַ���Ҳ��������������ͬ���ַ��������Խ�next[0]��Ϊ0
    int j = 1;
    int k = 0;
    while(j+1 < len)
    {
        if(k == -1 || sub[j] == sub[k])
        {
            next[++j] = ++k;
        }
        else
        {
            k = next[k];//***
        }
    }
}

void GetNextval(const char *sub,int *next)//j���˵�j==kʱ,�������ǰ���ַ�һ��,�����ж����Ч�ıȽ�,������Ҫ�Ľ�Ϊnextval������kֵ,�������ǰ���ַ�һ��,��k��Ϊ-1
{
    int len = strlen(sub);
    next[0] = -1;
    next[1] = 0;
    int j = 1;
    int k = 0;
    while(j+1 < len)
    {
        if(k == -1 || sub[j] == sub[k])
        {
            next[++j] = ++k;
        }
        else
        {
            k = next[k];//***
        }
    }
    int *nextval = (int *)malloc(len*sizeof(int));
    nextval[0] = -1;
    for(int i = 1;i < len;i++)
    {
        if(sub[i] == sub[next[i]])
        {
            nextval[i] = nextval[next[i]];
        }
        else
        {
            nextval[i] = next[i];
        }
    }
    for(int i = 0;i < len;i++)
    {
        next[i] = nextval[i];//����ٽ�nextval�е�kֵ������next��
    }
    free(nextval);
}
//KMP�㷨�����ص���i������,jֻ��Ҫ���˵��ʵ���λ�ü�j==k;
int KMP(const char *str,const char *sub,int pos)//O(n+m)
{
    int i = pos;
    int j = 0;
    int lenstr = strlen(str);
    int lensub = strlen(sub);
    if(i < 0 || i >= lenstr)//��겻��������֮ǰ��֮��
    {
        return -1;//û�ҵ�
    }
    int *next = (int *)malloc(lensub*sizeof(int));//����next���������Ԫ�ص�Kֵ
    GetNextval(sub,next);
    while(i < lenstr && j < lensub)
    {
        if(j == -1 || str[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            //i������
            j = next[j];
        }
    }
    free(next);
    if(j == lensub)
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char *str = "I am a student";
    char *sub = "student";
    //printf("%d\n",BF(str,sub,0));//��ӡ�Ӵ��������е�һ�γ��ֵĵ�һ���±�
    printf("%d\n",KMP(str,sub,4));
    return 0;
}

