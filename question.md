����������n����Χ��һ��Ȧ��˳���źţ��ӵ�һ���˿�ʼ��������������m�����Ǳ���m���˶�Ӧ���˳�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ��


��������c������д��������ѭ�������������������⣺

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

    i=0; //iΪÿ��ѭ��ʱ�ļ�������
    k=0;//kΪ��1,2,3����ʱ�ļ�ʱ������
    m=0;//mΪ�˳�������
    while(m<n-1)  //ģ����Ϸ���̣��������˳�����������ѭ������������
    {
        if(*(p+i)!=0)
            k++;
        if(k==key)
        {
            *(p+i)=0;  //��ʾ����ŵĺ����˳���Ϸ��
            k=0;
            m++;
        }

        i++;

        if(i==n)  i=0; //������һ��Ȧ�ӣ�����Ҫ�����ַ�ʽ������
    }

    while(*p==0)  //������Ҫע������ǰ����ָ���������ķ�ʽԭ��pһֱָ������ĵ�һ��Ԫ��
        p++;  //���������ֱ�Ӹı���ָ���ָ�򣬶�ǰ���������û�иı䡣

    printf("the last one is NO.%d\n\n",*p);
    return 0;
}

������c++���ԣ����������õ�����������������⣺
#include <iostream>
using namespace std;

struct linklist
{
    int idata;
    linklist *next;
};

linklist *present,*head;   //����ͨ��ȫ�ֱ���������������ͬ����֮��Ľ���������

void creat(int n);
void gamestart(int n,int m);
int main()
{
    int m,n;
    cin>>n>>m;
    creat(n);
    gamestart(n,m);
    cout<<"��"<<present->idata<<"�����ӽ����ʤ����"<<endl;
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
    while(n!=1)//�Լ��뵽�˽�������ȴû���뵽��ôͨ������������ѭ��
    {
        int j;
        for(j=1;j<m;j++)     //�����ʵ����һ���ؼ�������ͨ��һ��ָ�벻�ϵ�������֮��仯��ģ����Ϸ���̡�
        {
            pguard=present;
            present=present->next;
        }
        pguard->next=present->next;
        delete present;
        present=pguard->next;   //��ɾ��������һ���ڵ���ſ�ʼѭ����
        n--;
    }
}
