
#include"node.h"
#include<iostream>
using namespace std;

class linklist
{
  public:
      linklist(int i,char c);
      linklist(const linklist &l);
      ~linklist();
      bool locate(int i);
      bool locate(char c);
      bool Insert(int i=0,char c='0');    //在当前结点之后插入结点。
      bool Delete();           //删除当前结点。
      void show();     //显示链表所有内容。
      void Destroy();   //清除整个链表 用链表类的对象来创建。
  private:
    node head;  //头结点
    node *pcurrent;  //当前结点指针。这里有一个关键点，pcurrent应该也是属于链表结点类的，这说明在node外部的指针也是可以直接获得node类对象的地址的。
};

linklist::linklist(int i,char c):head(i,c)
{
    cout<<"linklist constructor is running"<<endl;
    pcurrent=&head;   //这是构造函数，用来初始化一个新创建的链表，所以不必使用参数来给pcurrent进行赋值，只要把head的值赋给它就行了。

}

linklist::linklist(const linklist &l):head(l.head)   //拷贝构造函数同样是构造函数，也是在对象创建时就调用的，它与其他的构造函数也算是重载关系，因此在开始要把head地址给pcurrent，链表类的构造函数是否都要调用内部结点类的构造函数
{                                   //仍然是结点的构造函数先运行。
    cout<<"linklist deep cloner is running..."<<endl;
    pcurrent=&head;   //head虽然没有值，但是在pcurrent之前被创建，已经有了相应的空间，所以可以如此赋值。
    node *ptemp=l.head.next;
    while(ptemp!=NULL)
    {
        node *pt=new node(ptemp->idata,ptemp->cdata,pcurrent,NULL);
        //新建结点并且复制idata和cdata,在这里方便的进行往前连接的操作，
        pcurrent->next=pt;//通过这个函数可以将链表向后连接。进而形成双链。
        pcurrent=pcurrent->next;
        ptemp=ptemp->next;   //ptemp就是通过这样的方式一步步往下的
    }

    pcurrent=&head;

}

linklist::~linklist()
{
    cout<<"linklist destructor is running..."<<endl;
    Destroy();
}

bool linklist::locate(int i)  //通过i来进行定位
{
    node *ptemp;
    ptemp=&head;
    while(ptemp!=NULL)
    {
        if(ptemp->idata==i)   //在链表类当中直接访问链表结点类中的内容。
        {
            pcurrent=ptemp;
            return true;
        }
        ptemp=ptemp->next;  //这样就像对结构体链表进行操作一样。

    }
    return false;
}

bool linklist::locate(char c)
{
    node *pt2=NULL;
    pt2=&head;
    while(pt2!=NULL)
    {
        if(c==pt2->cdata)
        {
            pcurrent=pt2;
            return true;
        }
        pt2=pt2->next;
    }
    return false;
}

bool linklist::Insert(int i,char c)
{
    //node *temp=NULL;
    node *ptr=new node(i,c,pcurrent,pcurrent->next);
    pcurrent->next=ptr;
    /*temp=ptr->next;  //以下两步设置插入结点之后的那个结点的前继结点。
    temp->piror=ptr;*/
    return true;
}

bool linklist::Delete()    //删除当前结点。。。。。。
{
    node *temp1=NULL,*temp2=NULL;
    temp1=pcurrent->piror;
    temp2=pcurrent->next;
    temp2->piror=temp1;
    temp1->next=temp2;

    delete [] pcurrent;
     node::count--;
    //node::change();           //静态成员函数可以被某个类的友元类调用，但是在这里实验的时候发现静态成员数据在友元类里也可以调用，只不过要加上域名。
    return true;
}

void  linklist::show()
{
    pcurrent=&head;
    while(pcurrent!=NULL)
    {
        cout<<pcurrent->idata<<"   "<<pcurrent->cdata<<endl;
        pcurrent=pcurrent->next;
    }
}

void linklist::Destroy()
{
    node *temp1=NULL,*temp2=NULL;
    temp1=head.next;


    while(temp1!=NULL)
    {
        temp2=temp1->next;
        delete temp1;
        temp1=temp2;
    }
    head.next=NULL;
    //temp1=&head;
    //temp1=head.next;
    //delete temp1;
    /*while(temp1!=NULL)         //这段代码逻辑有问题，运行结束式总会提示有指针访问的问题，需要认真分析加以改正。
    {
        temp2=temp1;
        temp1=temp1->next;
        delete temp2;
    }
    return;*/
}
