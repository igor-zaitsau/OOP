#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//класс исключения "деление на ноль"
class ZeroDivideException
{

};
//класс исключения "корень из отрицательного числа"
class SqrtException
{

};
//класс исключения "выход за пределы индексов массива"
class IndexException
{

};
//класс исключения "логарифм от отрицательного чилса"
class LogException
{

};



int setN(int i)
{
    int n;
    cout << "Enter n" << i << ": ";
    cin >> n;
    return n;
}


int main()
{

    int n1, n2, n3, i=0, MAX=10, MIN=-10;
    double x=-3;
    srand(time(NULL));
    do
    {
            n1 = setN(1);
            n2 = setN(2);
            n3 = setN(3);
            cout << endl;
    }while(n1 == n2 || n2 == n3 || n1 == n3 || n1<=0 || n2<=0 || n3<=0);

    double *a = new double[n1],
    *b = new double[n2],
    *c = new double[n3];

    for(x=-3; x<=7; x+=0.5)
    {
        try
        {

        if(i >= n1)
        {
            throw IndexException();
        }
        if(x==-1)
        {
            throw ZeroDivideException();
        }
        double temp = (x-1)/(x+1);
        if(temp<=0)
        {
            throw LogException();
        }
        a[i] = log(temp);
        cout << "a[" << i << "] = " << a[i] << endl;
        i++;
        }
        catch(IndexException)
        {
            cout << "Caught IndexException\n";
            break;
        }
        catch(ZeroDivideException)
        {
            a[i] = 0;
            cout << "a[" << i << "] = " << a[i] <<" - Caught ZeroDivideException"<<endl;
            i++;
        }
        catch(LogException)
        {
            a[i] = 0;
            cout << "a[" << i << "] = " << a[i] <<" - Caught LogException"<<endl;
            i++;
        }
    }

    for(i; i<n1; i++)
    {
        a[i] = 0;
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    cout << endl;

    for(i=0; i<n2; i++)
    {
        b[i] = (float)rand()/RAND_MAX * (MAX-MIN)+(MIN);
        if(b[i]>-1 && b[i]<1)
        {
            b[i] = 0;
        }
        cout << "b[" << i <<"] = " << b[i] << endl;
    }

    cout << endl;

    for(i=0; i<n3; i++)
    {
        try
        {

            if(i>=n1)
            {
                throw IndexException();
            }
            if(i>=n2)
            {
                throw IndexException();
            }
            double temp = a[i]+b[i];
            if(temp<0)
            {
                throw SqrtException();
            }
            c[i] = sqrt(temp);
            cout << "c[" << i <<"] = " << c[i] <<endl;
        }
        catch(SqrtException)
        {
            c[i] = 0;
            cout << "c[" << i <<"] = " << c[i] <<" - Caught SqrtException"<<endl;
        }
        catch(IndexException)
        {
            cout << "Caught IndexException" << endl;
            break;
        }
    }

    for(i; i<n3; i++)
    {
        c[i] = 0;
        cout << "c[" << i <<"] = " << c[i] << endl;
    }

    delete []a;
    delete []b;
    delete []c;
    return 0;
}
