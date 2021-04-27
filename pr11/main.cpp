#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <ctime>

using namespace std;

int main()
{
    int N = 10, i;
    vector<int> V(N);
    srand(time(NULL));
    for(i=0; i<N; i++)
    {
        V[i] = rand()%21-10;
        cout << V[i] << " ";
    }

    cout << endl;
     set<int> mySet;
    for(i=0; i<N; i++)
    {
        mySet.insert(V[i]);
    }
    auto begin = ++mySet.rbegin();
    auto end = --mySet.rend();
    copy( begin, end, ostream_iterator<int>(cout, " "));;
    return 0;
}
