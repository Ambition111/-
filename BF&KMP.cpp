#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//字符串查找

//str 主串，sub 子串，pos 光标起始位置
int BF(const char *str,const char *sub,int pos)//(BF算法) 普通查找法。O(n*m) n为主串长度 m为子串长度。
{
    int i = pos;
    int j = 0;
    int lenstr = strlen(str);
    int lensub = strlen(sub);
    if(i < 0 || i >= lenstr)//光标不能在主串之前和之后
    {
        return -1;//没找到
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
            i = i - j + 1;//i回退到刚才的位置的下一个
            j = 0;
        }
    }
    if(j == lensub)//找到了
    {
        return i-j;
    }
    else//没找到
    {
        return -1;
    }    
}
//***************************************************************************************

void GetNext(const char *sub,int *next)//j回退到j==k时,如果回退前后字符一样,则会进行多次无效的比较,所以需要改进为nextval数组存放k值,如果回退前后字符一样,则将k置为-1
{
    int len = strlen(sub);
    next[0] = -1;//光标在主串第一个元素前时，pos前没有字符，就不可能有两个相同的字符串，所以将next[0]置为-1
    next[1] = 0;//光标在主串第二个元素前时，pos前只有一个字符，也不可能有两个相同的字符串，所以将next[0]置为0
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

void GetNextval(const char *sub,int *next)//j回退到j==k时,如果回退前后字符一样,则会进行多次无效的比较,所以需要改进为nextval数组存放k值,如果回退前后字符一样,则将k置为-1
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
        next[i] = nextval[i];//最后再将nextval中的k值拷贝到next中
    }
    free(nextval);
}
//KMP算法最大的特点是i不回退,j只需要回退到适当的位置即j==k;
int KMP(const char *str,const char *sub,int pos)//O(n+m)
{
    int i = pos;
    int j = 0;
    int lenstr = strlen(str);
    int lensub = strlen(sub);
    if(i < 0 || i >= lenstr)//光标不能在主串之前和之后
    {
        return -1;//没找到
    }
    int *next = (int *)malloc(lensub*sizeof(int));//数组next存放主串各元素的K值
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
            //i不回退
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
    //printf("%d\n",BF(str,sub,0));//打印子串在主串中第一次出现的第一个下标
    printf("%d\n",KMP(str,sub,4));
    return 0;
}

