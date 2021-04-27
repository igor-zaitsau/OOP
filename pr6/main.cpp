#include <iostream>

using namespace std;

enum food
{
    grazing, predation, parasitism //выедание, хищничество, паразитизм
};

enum habitat
{
    terrestrial, underground, aquatic, aerial, woody //наземные, подземные, водные, воздушные, древесные
};

enum continents
{
    Eurasia, Africa, North_America, South_America, Australia, Antarctica
};

class Mammals
{protected:
    int weight;
    food a;
    habitat b;

public:
    Mammals(int weight, food a, habitat b)
    {
        this->weight = weight;
        this->a = a;
        this->b = b;
    }
    Mammals(){}

    string GetVivod()
    {
        string str = "_______________________\nWeight: " + to_string(weight) + " kg\nFood: ";
        switch(a)
        {
        case grazing: {str += "grazing";} break;
        case predation: {str += "predation";} break;
        case parasitism: {str += "parasitism";} break;
        }

        str += "\nHabitat: ";

        switch(b)
        {
        case terrestrial: {str += "terrestrial";} break;
        case underground: {str += "underground";} break;
        case aquatic: {str += "aquatic";} break;
        case aerial: {str += "aerial";} break;
        case woody: {str += "woody";} break;
        }

        str += "\nContinents: ";

        return str;
    }
};

class Regions
{
protected:
    continents c;
public:
    Regions(continents c)
    {
        this->c = c;
    }
    Regions(){}

    void GetC()
    {
        switch(c)
        {
            case Eurasia: cout << "Eurasia\n"; break;
            case Africa: cout << "Africa\n"; break;
            case North_America: cout << "North America\n"; break;
            case South_America: cout << "South America\n"; break;
            case Australia: cout << "Australia\n"; break;
            case Antarctica: cout <<"Antarctica\n"; break;
        }
    }

};

class Predators : public Mammals, public Regions
{
public:
    Predators(int weight, habitat b, continents c) : Mammals(), Regions()
    {
        this->weight = weight;
        this->a = predation;
        this->b = b;
        this->c = c;

    }
};

class Herbivores : public Mammals, public Regions
{
public:
    Herbivores(int weight, habitat b, continents c) : Mammals(), Regions()
    {
        this->weight = weight;
        this->a = grazing;
        this->b = b;
        this->c = c;
    }
};

food function1(int a)
{
    switch(a)
    {
        case 1: return grazing;
        case 2: return predation;
        case 3: return parasitism;
    }
}

habitat function2(int b)
{
    switch(b)
    {
        case 1: return terrestrial;
        case 2: return underground;
        case 3: return aquatic;
        case 4: return aerial;
        case 5: return woody;
    }
}

continents function3(int c)
{
    switch(c)
    {
        case 1: return Eurasia;
        case 2: return Africa;
        case 3: return North_America;
        case 4: return South_America;
        case 5: return Australia;
        case 6: return Antarctica;
    }
}

int main()
{
int a, b, c, weight;

cout << "Enter weight: ";
cin >> weight;

cout <<"\n1. Grazing\n2. Predation\n3. Parasitism\nEnter number: ";
cin >> a;

cout <<"\n1. Terrestrial\n2. Underground\n3. Aquatic\n4. Aerial\n5. Woody\nEnter number: ";
cin >> b;

cout <<"\n1. Eurasia\n2. Africa\n3. North America\n4. South America\n5. Australia\n6. Antarctica\nEnter number: ";
cin >> c;

Mammals first(weight, function1(a), function2(b));
Regions second(function3(c));
Predators third(weight, function2(b), function3(c));
Herbivores fourth(weight, function2(b), function3(c));

cout <<first.GetVivod();
second.GetC();
    return 0;
}
