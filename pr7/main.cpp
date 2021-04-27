#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Point
{private:
    T coordinate, coordinate2;
    string color;
public:
    Point(T a=0, T b=0, string c = " ") : coordinate(a), coordinate2(b), color(c){}

    void new_coordinate(T x, T y)
    {
        this->coordinate = x;
        this->coordinate2 = y;
    }
    void draw()
    {
        cout << coordinate << "\t" <<coordinate2 << "\t" << color<< endl;
    }

    void erase1()
    {
        this->coordinate = 0;
        this->coordinate2 = 0;
        this->color = " ";
    }

    void move1(Point &a)
    {
        cout << a.coordinate <<"\t" << a.coordinate2;
    }

    void vivod();

    float operator - (Point &a)
    {
       float x = (sqrt((pow(this->coordinate - a.coordinate, 2) + pow(this->coordinate2 - a.coordinate2,2))));
       return x;
    }
    Point operator -= (int x)
    {
        return Point(this->coordinate - x, this->coordinate2 - x);
    }
    Point operator += (int x)
    {
        return Point(this->coordinate + x, this->coordinate2 + x);
    }
};

template <typename T>
T enter_x()
{   T x;
    cout << "Enter a coordinate(x): ";
    cin >> x;
    return x;
 }

template <typename T>
T enter_y()
{   T y;
    cout << "Enter a coordinate(y): ";
    cin >> y;
    cout << "-----------------------------\n";
    return y;
 }



int main()
{   setlocale(LC_ALL, "");
    int x, y, z, key;

    x = enter_x<int>();
    y = enter_y<int>();
    Point <int>first(x, y, "RED");
    x = enter_x<int>();
    y = enter_y<int>();
    Point <int>second(x, y, "GREEN");

    cout << "0. Exit\n1. Erase coordinates\n2. Move coordinates\n3. Distance between coordinates\n4. Draw:(\n5. Change coordinates\n";

    do{
        cout << "\nChoose a number: ";
        cin >> key;
        switch(key)
        {
            case 1: first.erase1(); second.erase1(); cout << "Coordinates erased!!!"<<endl; break;
            case 2: {cout << "How much will we move the coordinates?: ";
                     cin >> z;
                     if(z>0)
                     {
                        first = (first +=z);
                        first.move1(first);
                        cout << endl;
                        second = (second +=z);
                        second.move1(second);
                     }
                     else
                     {
                        first = (first -=(-1*z));
                        first.move1(first);
                        cout << endl;
                        second = (second -=(-1*z));
                        second.move1(second);
                     }
                     break;
                    }
            case 3: {float theed = second - first; cout << "Distance between coordinates:\n" << theed; } break;
            case 4: first.draw(); second.draw(); cout <<"Drew:)"; break;
            case 5: {x = enter_x<int>(); y = enter_y<int>(); first.new_coordinate(x, y);
                     x = enter_x<int>(); y = enter_y<int>(); second.new_coordinate(x, y);
                    }break;
        }
    }while(key!=0);

    return 0;
}
