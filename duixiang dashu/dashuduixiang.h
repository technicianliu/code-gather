#include <iostream>
using namespace std;

class integer
{
    private:
        char *num;

    public:
        integer();
        integer(char *ch);
        ~integer();
        void set_value(char ch[]);
        bool show();

        friend void reverse(char *ch);

        friend ostream& operator<<(ostream &out,integer &b);
        friend istream& operator>>(istream &in,integer &b);
        friend integer& operator+(integer &a,integer &b); //Ϊ�˷���ϰ�ߣ����ﲢ����������
        friend integer& operator-(integer &a,integer &b);
        friend integer& operator*(integer &a,integer &b);
};

