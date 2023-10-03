#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str = "amitkumar";
    int n = 9;
    int l = 0, h = n - 1;
    cout << "Before " << str << endl;

    while (l < h)
    {
        swap(str[l++], str[h--]);
    }
    cout << "After " << str << endl;

    return 0;
}