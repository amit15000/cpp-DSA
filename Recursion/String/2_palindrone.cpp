#include <bits/stdc++.h>
using namespace std;

// void reverse_string(char str[], int l, int h)
void reverse_string(string &str, int l, int h)
{

    if (l >= h)
        return;

    swap(str[l++], str[h--]);

    reverse_string(str, l, h);

    return;
}

int main()
{

    // char str[] = "amitkumar";
    string str = "1101";
    string temp = str;
    // int n = strlen(str);
    int n = str.size();
    cout << "Before " << str << endl;

    reverse_string(str, 0, n - 1);
    cout << "After " << str << endl;

    if (temp == str)
    {
        cout << "Palindrone" << endl;
    }
    else
    {
        cout << "Not Palindrone" << endl;
    }
    return 0;
}