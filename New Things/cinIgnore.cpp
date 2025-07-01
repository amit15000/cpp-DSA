#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    string line;
    cin.ignore();
    cin.ignore(5, '\n'); // skip up to 1000 chars or until newline
    getline(cin, line);

    cout << "x :" << x << " line : " << line;
}