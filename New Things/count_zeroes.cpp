#include <iostream>
using namespace std;

unsigned int clz(unsigned int num)
{
    return __builtin_clz(num);
}

unsigned int ctz(unsigned int num)
{
    return __builtin_ctz(num);
}

int main()
{
    string str = "0010010000";

    int num = stoi(str);
    cout << "Count Leading Zeroes :" << num << " " << clz(5) << endl;
    cout << "Count Trailing Zeroes :" << ctz(num) << endl;
}