#include "dashuduixiang.h"
#include <iostream>
#include <cstring>  //要么写成cstring,要么写成string.h
using namespace std;

integer::integer()
{
    int i;
    num=new char[200];
    for(i=0;i<200;i++)
        num[i]='\0';

}
integer::integer(char *ch)
{
    int i;

    num=new char[200];
    for(i=0;ch[i]!='\0';i++)
    {
        num[i]=ch[i];
    }
    num[i]='\0';
}

integer::~integer()
{
    delete []num;
}

void integer::set_value(char *ch)
{
    delete []num;//防止前面已经被赋予非零值
    int i;

    num=new char[200];
    for(i=0;ch[i]!='\0';i++)
    {
        num[i]=ch[i];
    }
    num[i]='\0';
}

bool integer::show()
{

    cout<<num;
    cout<<endl;
    return true;
}

void reverse(char *ch)
{
    int i,n;
    char temp;
    for(i=0;ch[i]!='\0';i++){}
    n=i;
    for(i=0;i<n/2;i++)
    {
        temp=ch[i];
        ch[i]=ch[n-i-1];
        ch[n-i-1]=temp;
    }
}

istream& operator>>(istream &in,integer &b)
{

    in>>b.num;
    return in;//这里的in返回是为了连续输入多个大整数
}

ostream& operator<<(ostream& out,integer &b)
{

    out<<b.num;
    out<<endl;
    return out;
}

integer& operator+(integer &a,integer &b)
{
    int result[200]={0},i=0,temp;

    reverse(a.num);
    reverse(b.num);

    while(a.num[i]!='\0'&&b.num[i]!='\0')
    {
         temp=a.num[i]-'0'+b.num[i]-'0';
         result[i]=result[i]+temp%10;
         result[i+1]=result[i+1]+temp/10;
         i++;
    }

    while(a.num[i]!='\0')
    {
        result[i]=result[i]+a.num[i];
        if(result[i]>=10)
        {
            result[i+1]+=1;
            result[i]=result[i]%10;
        }

        i++;
    }

    while(b.num[i]!='\0')
    {
        result[i]=result[i]+b.num[i]-'0';
        if(result[i]>=10)
        {
            result[i+1]+=1;
            result[i]=result[i]%10;
        }

        i++;
    }

    for(i=199;i>=0;i--)
    {
        if(result[i]!=0)
            break;
    }
    temp=0;
    for(;i>=0;i--)
    {
        a.num[temp]=result[i]+'0';
        temp++;
    }
    a.num[temp]='\0';

    return a;

}

integer& operator*(integer &a,integer &b)
{
    //这个乘法是自己想出来的，除了最后的输出之外觉得效率比较高
    int result[200]={0},temp[200]={0};
    int i,j,k;
    int weight;

    reverse(a.num);
    reverse(b.num);

    for(i=0;a.num[i]!='\0';i++)
    {
        k=i;
        for(j=0;b.num[j]!='\0';j++)
        {
            temp[k]=(a.num[i]-'0')*(b.num[j]-'0');
            k=k+1;
        }

        for(j=i;j<k;j++)
        {
            weight=temp[j]/10;
            temp[j+1]=temp[j+1]+weight;
            temp[j]=temp[j]%10;
        }

        if(temp[j]!=0)
            k=k+1;


        for(j=i;j<k;j++)
        {
            result[j]=temp[j]+result[j];

            if(result[j]>=10)
            {
                result[j+1]=result[j+1]+1;
                result[j]=result[j]-10;
            }
        }

        if(result[j]>=10)
        {
             result[j+1]=result[j+1]+1;
             result[j]=result[j]-10;
        }

        for(k=0;k<200;k++)
        {
        if(temp[k]!=0)
            temp[k]=0;
        else
            break;
        }
    }



    for(i=199;i>=0;i--)
    {
        if(result[i]!=0)
            break;
    }

    j=0;
    for(;i>=0;i--)
     {
         a.num[j]='0'+result[i];
         j++;
     }
     return a;
}

integer& operator-(integer &a,integer &b)
{
    //真正实现减法的代码很短，比较两个数的大小废了一段时间
    int len_a,len_b,n,i,temp=0,key=0; //key用来记录a和b的大小
    char Max[200]={'\0'},Min[200]={'\0'};
    int result[200]={0};

    for(i=0;a.num[i]!='\0';i++){}
    len_a=i;
    for(i=0;b.num[i]!='\0';i++){}
    len_b=i;

    if(len_a>len_b)
    {
        key=1;
        strcpy(Max,a.num);
        strcpy(Min,b.num);
    }

    if(len_a<len_b)
    {
        key=-1;
        strcpy(Max,b.num);
        strcpy(Min,a.num);
    }

    if(len_a==len_b)
    {
        if(strcmp(a.num,b.num)>=0)
         {
              key=1;
              strcpy(Max,a.num);
              strcpy(Min,b.num);
         }

        else if(strcmp(a.num,b.num)<0)
        {
            key=-1;
            strcpy(Max,b.num);
            strcpy(Min,a.num);
        }
    }

    reverse(Max);
    reverse(Min);

    i=0;
    while(Max[i]!='\0'&&Min[i]!='\0')
    {
        result[i]=result[i]+(Max[i]-'0')-(Min[i]-'0');
        i++;
    }
    while(Max[i]!='\0')
    {
        result[i]=result[i]+Max[i]-'0';
        i++;
    }
    n=i;
    for(i=0;i<n-1;i++) //之所以放在这里是考虑到了连续借位的情况
    {
        if(result[i]<0)
        {
            result[i+1]=result[i+1]-1;
            result[i]=result[i]+10;
        }
    }

    for(i=99;i>=0;i--)
    {
        if(result[i]!=0)
            break;
    }

    if(key==1)
    {
        for(;i>=0;i--)
        {
            a.num[temp]=result[i]+'0';
            temp++;
        }
    }
    if(key==-1)
    {
        a.num[temp++]='-';
        for(;i>=0;i--)
        {
            a.num[temp]=result[i]+'0';
            temp++;
        }
    }

    return a;
}
