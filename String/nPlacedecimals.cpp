#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t = 10;                                                               // Assuming t is an integer
    t = static_cast<double>(t);                                               // Convert t to a double
    cout << fixed << setprecision(5) << static_cast<double>(100) / 8 << endl; // Output: 10.0
    return 0;
}
