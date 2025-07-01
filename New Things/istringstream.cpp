#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string data = "123 456 789";
    int a, b, c;

    istringstream ss(data);

    ss >> a >> b >> c;

    cout << a << b << c;
}