#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "45acb2";
    size_t idx;
    cout << stoi(str, &idx) << endl;
    cout << str.substr(idx);

    return 0;
}
