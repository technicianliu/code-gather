
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
      bool Insert(int i=0,char c='0');    //�ڵ�ǰ���֮������㡣
      bool Delete();           //ɾ����ǰ��㡣
      void show();     //��ʾ�����������ݡ�
      void Destroy();   //����������� ��������Ķ�����������
  private:
    node head;  //ͷ���
    node *pcurrent;  //��ǰ���ָ�롣������һ���ؼ��㣬pcurrentӦ��Ҳ��������������ģ���˵����node�ⲿ��ָ��Ҳ�ǿ���ֱ�ӻ��node�����ĵ�ַ�ġ�
};

linklist::linklist(int i,char c):head(i,c)
{
    cout<<"linklist constructor is running"<<endl;
    pcurrent=&head;   //���ǹ��캯����������ʼ��һ���´������������Բ���ʹ�ò�������pcurrent���и�ֵ��ֻҪ��head��ֵ�����������ˡ�

}

linklist::linklist(const linklist &l):head(l.head)   //�������캯��ͬ���ǹ��캯����Ҳ���ڶ��󴴽�ʱ�͵��õģ����������Ĺ��캯��Ҳ�������ع�ϵ������ڿ�ʼҪ��head��ַ��pcurrent��������Ĺ��캯���Ƿ�Ҫ�����ڲ������Ĺ��캯��
{                                   //��Ȼ�ǽ��Ĺ��캯�������С�
    cout<<"linklist deep cloner is running..."<<endl;
    pcurrent=&head;   //head��Ȼû��ֵ��������pcurrent֮ǰ���������Ѿ�������Ӧ�Ŀռ䣬���Կ�����˸�ֵ��
    node *ptemp=l.head.next;
    while(ptemp!=NULL)
    {
        node *pt=new node(ptemp->idata,ptemp->cdata,pcurrent,NULL);
        //�½���㲢�Ҹ���idata��cdata,�����﷽��Ľ�����ǰ���ӵĲ�����
        pcurrent->next=pt;//ͨ������������Խ�����������ӡ������γ�˫����
        pcurrent=pcurrent->next;
        ptemp=ptemp->next;   //ptemp����ͨ�������ķ�ʽһ�������µ�
    }

    pcurrent=&head;

}

linklist::~linklist()
{
    cout<<"linklist destructor is running..."<<endl;
    Destroy();
}

bool linklist::locate(int i)  //ͨ��i�����ж�λ
{
    node *ptemp;
    ptemp=&head;
    while(ptemp!=NULL)
    {
        if(ptemp->idata==i)   //�������൱��ֱ�ӷ������������е����ݡ�
        {
            pcurrent=ptemp;
            return true;
        }
        ptemp=ptemp->next;  //��������Խṹ��������в���һ����

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
    /*temp=ptr->next;  //�����������ò�����֮����Ǹ�����ǰ�̽�㡣
    temp->piror=ptr;*/
    return true;
}

bool linklist::Delete()    //ɾ����ǰ��㡣����������
{
    node *temp1=NULL,*temp2=NULL;
    temp1=pcurrent->piror;
    temp2=pcurrent->next;
    temp2->piror=temp1;
    temp1->next=temp2;

    delete [] pcurrent;
     node::count--;
    //node::change();           //��̬��Ա�������Ա�ĳ�������Ԫ����ã�����������ʵ���ʱ���־�̬��Ա��������Ԫ����Ҳ���Ե��ã�ֻ����Ҫ����������
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
    /*while(temp1!=NULL)         //��δ����߼������⣬���н���ʽ�ܻ���ʾ��ָ����ʵ����⣬��Ҫ����������Ը�����
    {
        temp2=temp1;
        temp1=temp1->next;
        delete temp2;
    }
    return;*/
}
