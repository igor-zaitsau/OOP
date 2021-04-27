#include <iostream>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

int main()
{
    int i, j, key, N=10;
    stack<int> steck;
    stack<int> steck2;
    vector<int> vect(N);
    srand(time(NULL));
    cout << "Stack with random values:" << endl;
    for(i=0; i<N; i++)
    {
        key=rand()%21-10;
        steck.push(key);
        cout << steck.top() <<" ";
        vect[i]=steck.top();
    }
    cout << "\nFinal stack variant:" << endl;
    for(i=0; i<N; i++)
    {
        if(vect[i]<0)
        {
            steck2.push(vect[i]);
            cout << steck2.top() << " ";
        }
    }
    for(i=0; i<N; i++)
    {
        if(vect[i]>=0)
        {
            steck2.push(vect[i]);
            cout << steck2.top() << " ";
        }
    }

    cout << endl;
    return 0;
}
