#include <iostream>
using namespace std;
int main()
{
    int shani[5] = {4, 6, 1, 8, 9};
    int size = sizeof(shani) / sizeof(shani[0]);
    cout << size << endl;

    cout << INT16_MAX << " ";
    cout << INT32_MAX << " ";
}
