#include <bits/stdc++.h>
using namespace std;
inline void numberShow(int i)
{

    cout << "Number is :" << i << endl;
}

int main()
{
    int i = 0;
    numberShow(i++);
    numberShow(i++);
    numberShow(i++);
    numberShow(i++);

    return 0;
}
// inline--- similar to Macro ( compiler replaces it blindly  during pre-processing)
//  inline---compiler replaces --at compile time(not blindly --- compiler optimization cheacks---code small==> then only replace)
//  done to decrease the function calls in stack.