#include <iostream>
using namespace std;
int main()
{
    string str = "abcdefgh";
    cout << str << endl;
    // cout << str.substr() << endl;
    // cout << str.substr(0) << endl;
    cout << str.substr(1) << endl;
    cout << str.substr(2) << endl;
    cout << str.substr(3, 4) << endl;

    /// (3,4) ==> 3 --- 3 index se lekar ke ---- 4 number of characters ---

    return 0;
}
