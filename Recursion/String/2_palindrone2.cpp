#include <bits/stdc++.h>
using namespace std;

bool check_palindrone(string &str, int i, int j)
{
    if (i >= j)
        return 1;

    if (str[i] != str[j])
    {
        return 0;
    }
    else
    {
        return check_palindrone(str, i + 1, j - 1);
    }
}

int main()
{

    // char str[] = "amitkumar";
    string str = "1101011";
    string temp = str;
    // int n = strlen(str);
    int n = str.size();

    bool x = check_palindrone(str, 0, n - 1);

    if (x)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not palindrome" << endl;
    }

    return 0;
}