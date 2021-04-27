#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{   string line;
    int x, i;
    ifstream in("input.txt", ios_base::in);
    ofstream out("output.txt", ios_base::out);
    if(in.is_open() && out.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;

            for (i=0; i < line.length(); i++)
            {
                if(line[i]=='*')
                {
                    x = i;
                    break;
                }
            }

            for(i=0; i <line.length(); i++)
            {
                if(i<=x)
                {
                    cout << line[i];
                    out << line[i];
                }
                else if(line[i]==' ' && i>x)
                {
                    cout <<  " ";
                    out << " ";
                }
                else
                {
                    cout << "-";
                    out << "-";
                }
            }

        }
        in.close();
        out.close();
        cout << endl;
     }
    else
    {
        cout << "Error opening file!!!" << endl << endl;
    }

    return 0;
}
