#include <iostream>
#include <list>
#include <iterator>
#include <ctime>


using namespace std;

int main()
{
        list<int> L;
        int N = 10, i, key;
        srand(time(NULL));
        for(i=1; i<=N; i++)
        {
            key = rand() % 21-10;
            L.push_back(key);
        }
        for(int data : L) cout << data << " " ;
        cout << endl;
        for(auto i = L.begin(); i != L.end();)
        {
            i = L.erase(++i);
        }
        for(int data : L) cout << data << " " ;
        cout << endl;
    return 0;
}
