#include <bits/stdc++.h>
using namespace std;

int main()
{

    int row = 4, num = 1;
    int sizes[] = {4, 3, 2, 5};

    int **jagged_array = new int *[row];

    for (int i = 0; i < row; i++)
    {
        jagged_array[i] = new int[sizes[i]];
    }

    // Insertion in array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            jagged_array[i][j] = num++;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << jagged_array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}