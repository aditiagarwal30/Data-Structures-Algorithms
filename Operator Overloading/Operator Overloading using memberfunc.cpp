#include<iostream>
using namespace std;

class Complex
{
    private:
    int a,b;
    public:
    void setData(int x,int y)
    {
        a=x;
        b=y;
    }
    void showData()
    {
        cout<<a<<" "<<b;
    }
    Complex add(Complex c)
    {
        Complex temp;
        temp.a= a+ c.a;
        temp.b= b+ c.b;
        return temp;
    }
};

int main()
{
    Complex c1,c2,c3;
    c1.setData(10,5);
    c2.setData(2,4);
    c3=c1.add(c2);
    c3.showData();
    return 0;
}



Complex operator+(Complex c)
{
    Complex temp;
    temp.a=a+c.a;
    temp.b=b+c.b;
    return temp;
}

//can be called by using

c3=c1.operator+(c2);

      or
c3= c1+c2;

