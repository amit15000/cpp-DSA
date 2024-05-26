#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;
        while (j--)
        {
            cout << " ";
        }
        j = i + 1;
        while (j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}