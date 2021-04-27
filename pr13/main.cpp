#include <iostream>
#include <fstream>


using namespace std;

class FilmLover
{
public:
    int bookCode, yearOfPublishing, rackNumber;
    string author, name;
    static int counter;

    FilmLover(){}

    FilmLover(int bookCode, int yearOfPublishing, int rackNumber, string author, string name)
    {
        this-> bookCode = bookCode;
        this-> yearOfPublishing = yearOfPublishing;
        this-> rackNumber = rackNumber;
        this-> author = author;
        this-> name = name;
    }
    void getRackNumber(string author, string name)
    {
        if(this-> author == author && this-> name == name)
        {
            cout << "\nAuthor: " << this-> author << endl;
            cout << "Name of the book: " << this-> name << endl;
            cout <<"Rack number: " << this-> rackNumber << endl << endl;
        }

    }
    void getListOfBook(string author)
    {
        if(this-> author == author)
        {
            cout << "\nList of the book: " << this-> name << endl << endl;
        }
    }
    void getYear(int year)
    {
        if(this-> yearOfPublishing == year)
        {
            counter++;
        }
    }

};

int FilmLover :: counter = 0;

int main()
{
    string author, name;
    int year, key;
    FilmLover first, second, third;

    ifstream fin("input.txt");
    fin >> first.bookCode >> first.yearOfPublishing >> first.rackNumber >> first.author >> first.name;
    fin >> second.bookCode >> second.yearOfPublishing >> second.rackNumber >> second.author >> second.name;
    fin >> third.bookCode >> third.yearOfPublishing >> third.rackNumber >> third.author >> third.name;

    cout << "0. Exit\n1. Book location\n2. Author's books\n3. Number of books in a given year\n";
    do{
       cout << "Enter number: ";
       cin >> key;
       cout << endl;
       switch(key)
       {
            case 0: break;
            case 1: {
                cout << "Enter author: ";
                cin >> author;
                cout << "Enter the title of the book: ";
                cin >> name;
                first.getRackNumber(author, name);
                second.getRackNumber(author, name);
                third.getRackNumber(author, name);
            } break;

            case 2: {
                cout << "Enter author: ";
                cin >> author;
                first.getListOfBook(author);
                second.getListOfBook(author);
                third.getListOfBook(author);
            } break;

            case 3: {
                cout << "Enter the year (XX): ";
                cin >> year;
                first.getYear(year);
                second.getYear(year);
                third.getYear(year);
                cout << "\nNumber of books published: " << FilmLover::counter << endl << endl;

            }break;
            default: cout << "Error!!! Try again" << endl << endl;
       }
    }while(key!=0);

    return 0;
}
