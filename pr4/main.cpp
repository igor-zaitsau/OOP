#include <iostream>

using namespace std;

class Error_programm
{
    public:
        string error;

        Error_programm()
        {
            error="ERROR!!!";
        }

        virtual void vivod()
        {
            cout <<error<<endl;
        }
};

class Error_memory : public Error_programm
{   public:
    string error_inf="An attempt was made to free a heap that was not previously allocated.";

     virtual void vivod()
        {
            Error_programm::vivod();
            cout <<error_inf<<endl;
        }
};

class Error_math : public Error_programm
{ public:
    string error_inf= "Sine and cosine range: -1 to 1";

     virtual void vivod()
        {
            Error_programm::vivod();
            cout <<error_inf<<endl;
        }

};

class Error_division : public Error_programm
{   public:
   string error_inf= "ERROR: You cannot divide by zero :(";

     virtual void vivod()
        {
            Error_programm::vivod();
            cout <<error_inf<<endl;
        }


};

class Error_overflow : public Error_programm
{   public:
   string error_inf= "ERROR: Buffer overflow";

     virtual void vivod()
        {
            Error_programm::vivod();
            cout <<error_inf<<endl;
        }

};

int main()
{
setlocale(LC_ALL,"");
int key;

cout <<"1.Error_programm\n2.Error_memory\n3.Error_math\n4.Error_division\n5.Error_overflow\n0.Exit\n"<<endl;

do
{
    cout << "Enter problem number: ";
    cin >> key;
    switch(key)
    {        case 0: break;
             case 1:
                {Error_programm error1; error1.vivod();
                break;}
             case 2:
                {Error_memory error2; error2.vivod();
                break;}
             case 3:
                {Error_math error3; error3.vivod();
                break;}
             case 4:
                {Error_division error4; error4.vivod();
                break;}
             case 5:
                {Error_overflow error5; error5.vivod();
                break;}
    }
}while(key!=0);

getchar();

return 0;
}
