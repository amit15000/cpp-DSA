#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "There are 4 apples, 3 bananas, 5 oranges";
    size_t idx;
    int num = stoi(str, &idx);
    cout << "First Number :" << stoi(str.substr(idx), &idx) << endl;
    cout << "Second Number :" << stoi(str.substr(idx), &idx) << endl;
    cout << "First Number :" << stoi(str.substr(idx), &idx) << endl;

    return 0;
}
