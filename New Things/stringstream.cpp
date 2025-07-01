#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string data = "123 456 789";

    stringstream ss(data);

    string d;
    while (ss >> d)
    {
        cout << d << " ";
    }
}