#include <iostream>
#include <math.h>
#define PI 3.141593

using namespace std;

class Circle{
    public:
    float r;

    Circle(){
        cout << "Enter the radius of the circle: ";
        cin >> r;
    }

    int check()
    {
        if(r<=0)
        {
            cout << "Error!!!\n";
            return -1;
        }
    }

    float area()
    {
        float s;
        s=PI*pow(r,2);
        cout << "Area = " << s <<endl;
        return s;

    }

    float length()
    {
        float p;
        p=2*PI*r;
        cout << "Length = " << p <<endl;
        return p;
    }

};



int main()
{   int a;
    ///класс объект-имя   создание-конструктор
    Circle   circle     = Circle();
    a=circle.check();
    if(a==-1)
    {
        return -1;
    }
    else
    {
    circle.area();
    circle.length();
    }
    return 0;
}
