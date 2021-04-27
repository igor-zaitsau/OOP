#include <iostream>
#include <stack>
#include <iterator>
#include <ctime>


using namespace std;

int main()
{
    stack<int> steck, steck2;

    int N = 10, i, key;
    srand(time(NULL));
    cout << "Stack of " << N <<" items:" << endl;
    for(i=1; i<=N; i++)
    {
        key = rand() % 21-10;
        steck.push(key);
        cout << steck.top() <<" ";
    }
    cout << "\nStack with no even elements:" << endl;
    for(i=1; i<=N/2; i++)
    {
        if(N%2==0)
        {
            steck2.push(steck.top());
            steck.pop();
            steck.pop();
            cout << steck2.top() << " ";
        }
        else
        {
            steck.pop();
            steck2.push(steck.top());
            steck.pop();
            steck.pop();
            cout << steck2.top() << " ";
        }
    }
    cout << endl;
    return 0;
}
