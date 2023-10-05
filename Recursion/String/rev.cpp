#include <bits/stdc++.h>
using namespace std;

// void reverse_string(char str[], int l, int h)
void reverse_string(string &str, int i, int n)
{
    if (i >= (n + 1) / 2)
        return;

    swap(str[i], str[(n - i - 1)]);

    i++;
    reverse_string(str, i, n);

    return;
}

int main()
{

    // char str[] = "amitkumar";
    string str = "Shashank";
    // int n = strlen(str);
    int n = str.size();
    cout << "Before " << str << endl;

    reverse_string(str, 0, n);
    cout << "After " << str << endl;
    return 0;
}