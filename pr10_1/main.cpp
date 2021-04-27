#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int N=15;
    int i, j;
    vector<int> mass(N);
    vector<int> mass2(N);
    cout << "Vector with random values:" << endl;
    for(i=0; i<N; i++)
    {
        mass[i]=rand()%21-10;
        cout << mass[i] <<" ";
    }
    for(i=0, j=0; i<N; i++)
    {
        if(mass[i]<0)
        {
            mass2[j]=mass[i];
            j++;
        }
    }
    for(i=0, j; i<N; i++)
    {
        if(mass[i]>=0)
        {
            mass2[j]=mass[i];
            j++;
        }
    }
    cout << "\nFinal vector variant:" << endl;

    for(i=0; i<N; i++)
    {
        cout << mass2[i] << " ";
    }
    cout << endl;
    return 0;
}
