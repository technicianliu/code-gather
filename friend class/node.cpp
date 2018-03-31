
#include"node.h"  //这里采用类的声明和类中的函数定义分离的方式：把所有声明都放在node.h当中，把所有的定义都放在node.cpp当中，在使用时仍然只包含node.h。
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
    idata=n.idata;  //类之外的东西不可以这样访问一个对象的数据，但是类内部的对像可以这样访问。。
    cdata=n.cdata;
    piror=n.piror;
    next=n.next;
    count++;       //这个公共财产不属于任何单个结点，它是所有结点的共有财产，可以这样单独使用。
}

node::node(int i,char c)
{
    idata=i;
    cdata=c;
    piror=NULL;
    next=NULL;
    count++;    //每当调用初始化函数，一定是新创建了结点，所以把count直接加一。

}

node::node(int i,char c,node *p,node *n)
{
    idata=i;
    cdata=c;
    piror=p;
    next=n;
    count++;
}


/*node::~node()         //关键在于怎么定义析构函数？
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
    cout<<n.idata<<"  "<<n.cdata<<endl;//友元函数定义在node.cpp之中，可以直接访问node类的私有成员数据。
}
