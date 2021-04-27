#include <iostream>
#include <clocale>

using namespace std;

class String {
    int size;
    char* mas;
public:
    String(string str) {
        this->size = str.size();
        mas = new char[size];
        for (int i = 0; i < size; i++) { mas[i] = str[i]; }
    }

    String(char* mas, int size) {
        this->size = size;
        this->mas = mas;
    }

    String operator = (string s) {
        int newStrSize = this->size + s.size();
        char newStr[newStrSize];
        int i;
        for (i = 0; i < this->size; i++) { newStr[i] = this->mas[i];}
        for (int j = 0; i < newStrSize; i++, j++) {newStr[i] = s[j];}
        return String(newStr, newStrSize);
    }

    String operator += (string s) {
        int newStrSize = this->size + s.size();
        char newStr[newStrSize];
        int i;
        for (i = 0; i < this->size; i++) { newStr[i] = this->mas[i];}
        for (int j = 0; i < newStrSize; i++, j++) {newStr[i] = s[j];}
        return String(newStr, newStrSize);
    }

    void print() {
        for(int i = 0; i < size; i++) { cout << mas[i]; }
        cout << endl;
    }

    friend std::ostream& operator<< (std::ostream &out, const String &string) {
        for(int i = 0; i < string.size; i++) { out << string.mas[i]; }
        out << endl;
    }

    friend std::istream& operator>> (std::istream &in, String &strin) {
        in >> strin.size;
        for (int i = 0; i < strin.size; i++) { in >> strin.mas[i];}
        return in;
    }
};

int main() {
    setlocale(LC_ALL, "");
    char a[3] = {'a', 'b', 'c'};
    String first(a, 3);
    cout << first;

    String second("hello");
    cin >> second;
    cout << second;
    (first = "dab").print();
    cout << (second += "cad");
    return 0;
}
