
#include"node.h"  //�������������������еĺ����������ķ�ʽ������������������node.h���У������еĶ��嶼����node.cpp���У���ʹ��ʱ��Ȼֻ����node.h��
#include<iostream>
using namespace std;
int node::count=0;
void shownode(node &n);
node::node()
{
    idata=0;
    cdata='c';
    piror=NULL;
    next=NULL;
    count++;
}
node::node(const node &n)
{
    idata=n.idata;  //��֮��Ķ�����������������һ����������ݣ��������ڲ��Ķ�������������ʡ���
    cdata=n.cdata;
    piror=n.piror;
    next=n.next;
    count++;       //��������Ʋ��������κε�����㣬�������н��Ĺ��вƲ���������������ʹ�á�
}

node::node(int i,char c)
{
    idata=i;
    cdata=c;
    piror=NULL;
    next=NULL;
    count++;    //ÿ�����ó�ʼ��������һ�����´����˽�㣬���԰�countֱ�Ӽ�һ��

}

node::node(int i,char c,node *p,node *n)
{
    idata=i;
    cdata=c;
    piror=p;
    next=n;
    count++;
}


/*node::~node()         //�ؼ�������ô��������������
{
    cout<<"node destructor is running"<<endl;
    count--;
}*/




/*bool node::setp(node *p)
{
    piror=p;
    return true;
}*/
int node::allocation()
{
    return count;
}
bool node::change()
{
    count--;
    return true;
}

void shownode(node &n)
{
    cout<<n.idata<<"  "<<n.cdata<<endl;//��Ԫ����������node.cpp֮�У�����ֱ�ӷ���node���˽�г�Ա���ݡ�
}
