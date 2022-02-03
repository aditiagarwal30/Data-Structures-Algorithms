#include<iostream>
using namespace std;
class Integer
{
private:
    int x;
public:
    void setData(int a)
    {
        x=a;
    }   
    void showData()
    {
        cout<<"x = "<<x<<endl;
    }
    Integer operator++()   // pre increment
    {
        Integer i;
        i.x= ++x;
        return i;
    }
    Integer operator++(int)  //post increment 
    {
        Integer i;
        i.x= x++;
        return i;
    }
};

int main()
{
    Integer i1,i2,i3;
    i1.setData(7);
    i1.showData();
    i2= ++i1;
    i1.showData();
    i2.showData();
    
    i3=i1++;
    i1.showData();
    i3.showData();
    
}