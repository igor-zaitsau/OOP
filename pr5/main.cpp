#include <iostream>

using namespace std;

enum quality
{
    low, middle, high
};

class Stool
{
public:
    float h;
    quality q;


virtual float amount_wood()
{
    if(q==low)
    {
        return 4*h+12;
    }
    else
    {
        return 5*h+14;
    }
}


virtual float price()
{
    float d = amount_wood();

    if(q==low)
    {
        return d*2;
    }
    else if(q==middle)
    {
        return d*3;
    }
    else
    {
        return d*4;
    }

}

string information()
{
    string str="Height: " + to_string(h) + "\nQuality: ";
    switch(q)
    {
        case low: {str += "low";} break;
        case middle: {str += "middle";} break;
        case high: {str += "high";} break;
    }
    str += "\nQuantity: " + to_string(amount_wood()) + "\nPrice: " + to_string(price());
    return str;
}
};


class Chair : public Stool
{
    public:
    float spinka;

    virtual float amount_wood()
    {
        return Stool::amount_wood()+2*spinka+5;
    }
};

int main()
{Stool first;
cout << "Enter the height of the stool: ";
cin >> first.h;
cout << "Product quality:\n 1.low;\n 2.middle;\n 3.high.\nChoose quality: ";
int n;
cin >> n;
switch(n)
{
    case 1: {first.q = low;} break;
    case 2: {first.q = middle;} break;
    case 3: {first.q = high;} break;
}
cout << "Stool:\n" << first.information() << endl;
Chair second;
cout << "Enter the height of the chair: ";
cin >> second.h;
cout << "Product quality:\n 1.low;\n 2.middle;\n 3.high.\nChoose quality: ";
cin >> n;
switch(n)
{
    case 1: {second.q = low;} break;
    case 2: {second.q = middle;} break;
    case 3: {second.q = high;} break;
}
cout << "Enter the height of spinka: ";
cin >> second.spinka;
cout << "Chair:\n" << second.information() << endl;

    return 0;
}
