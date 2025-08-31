#include <iostream>
#include <vector>
#include <algorithm> // For min and max functions
using namespace std;

void printPattern(const vector<int> &arr)
{
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    // Print pattern from top to bottom
    for (int i = maxVal; i >= minVal; --i)
    {
        for (int val : arr)
        {
            if (val == i)
                cout << "*\t";
            else
                cout << "_\t";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {5,3,4,-2,0,5,4,-3};
    printPattern(arr);
    return 0;
}
