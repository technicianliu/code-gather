#include <iostream>
#include"linklist.h"
using namespace std;

int main()
{
    int tempi;
    char tempc;
    cout<<"please input an intger and a character"<<endl;
    cin>>tempi>>tempc;
    linklist a(tempi,tempc);
    a.locate(tempc);
    a.Insert(1,'a');
    a.locate(1);
    a.Insert(2,'b');
    a.Insert(4,'h');
    cout<<"After insert.."<<endl;
    a.show();
    linklist b(a);
    a.locate(4);
    a.Delete();
    a.show();
    b.show();
    cout<<"node allocation:"<<node::allocation()<<endl;
    node c(100,'z');
    shownode(c);
    a.Destroy();
    b.Destroy();
    return 0;
}

