#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    // best case
    if (n == 0)
        return 1;

    int chhotiProblem = factorial(n - 1);
    int badiProblem = n * chhotiProblem;
    return badiProblem;

    // or

    // return n * factorial(n - 1);
}

int main()
{

    int n = 5;
    int ans = factorial(n);
    cout << ans;

    return 0;
}