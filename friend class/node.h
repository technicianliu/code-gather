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
     static bool change();   //�����Լ�дһ���������ı侲̬��Ա������ֵ��

  private:

     int idata;
     char cdata;
     node *piror;
     node *next;
     static int count;

};
