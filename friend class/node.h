class node
{
    friend void shownode(node &n);
    friend class linklist;
  public:
     node();
     node(const node &n);
     node(int i,char c='\0');
     node(int i,char c,node *p,node *n);


     static int allocation();
     static bool change();   //可以自己写一个函数来改变静态成员函数的值、

  private:

     int idata;
     char cdata;
     node *piror;
     node *next;
     static int count;

};
