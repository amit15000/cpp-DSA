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
                cout << " \t";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {4, -3, 2, 5};
    printPattern(arr);
    return 0;
}
