问题描述：n个人围成一个圈，顺序排号，从第一个人开始报数，输入整数m，凡是报到m的人都应该退出圈子，问最后留下的是原来第几号的那位？


以下是用c语言来写，仅仅用循环和数组来解决这个问题：

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,k,m,n,num[50],*p,key;
    scanf("%d%d",&n,&key);

    p=num;
    for(i=0;i<n;i++)
    {
        *(p+i)=i+1;

    }

    i=0; //i为每次循环时的计数变量
    k=0;//k为按1,2,3报数时的计时变量。
    m=0;//m为退出人数。
    while(m<n-1)  //模拟游戏过程，这里用退出人数来控制循环结束条件。
    {
        if(*(p+i)!=0)
            k++;
        if(k==key)
        {
            *(p+i)=0;  //表示该序号的孩子退出游戏。
            k=0;
            m++;
        }

        i++;

        if(i==n)  i=0; //由于是一个圈子，所以要用这种方式来返回
    }

    while(*p==0)  //这里需要注意由于前面用指针遍历数组的方式原因，p一直指向数组的第一个元素
        p++;  //这个做法是直接改变了指针的指向，而前面的做法并没有改变。

    printf("the last one is NO.%d\n\n",*p);
    return 0;
}

以下是c++语言，并且这里用到了链表，更加容易理解：
#include <iostream>
using namespace std;

struct linklist
{
    int idata;
    linklist *next;
};

linklist *present,*head;   //这里通过全局变量来建立两个不同函数之间的交流。。。

void creat(int n);
void gamestart(int n,int m);
int main()
{
    int m,n;
    cin>>n>>m;
    creat(n);
    gamestart(n,m);
    cout<<"第"<<present->idata<<"个孩子将获得胜利！"<<endl;
    return 0;
}

/*linklist* creat(int n)
{
    linklist *head,*p1,*p2;
    int i;
    p1=new linklist;
    p1->idata=1;
    head=p1;
    p2=p1;
    for(i=1;i<n;i++)
    {
        p1=new linklist;
        p1->idata=i+1;
        p2->next=p1;
        p2=p1;
    }
    p1->next=head;

    return head;
}*/

void creat(int n)
{

    int i;
    head=new linklist;
    head->idata=1;
    present=head;
    for(i=1;i<n;i++)
    {
        present->next=new linklist;
        present->next->idata=i+1;
        present=present->next;
    }

    present->next=head;

    present=head;

}

void gamestart(int n,int m)
{
    linklist *pguard;
    while(n!=1)//自己想到了结点个数，却没有想到怎么通过结点个数控制循环
    {
        int j;
        for(j=1;j<m;j++)     //这里的实现是一个关键。。。通过一个指针不断的在链表之间变化来模拟游戏过程。
        {
            pguard=present;
            present=present->next;
        }
        pguard->next=present->next;
        delete present;
        present=pguard->next;   //从删除结点的下一个节点接着开始循环。
        n--;
    }
}
