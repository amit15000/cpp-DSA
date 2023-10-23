#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> v(3, vector<int>(4, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    int num = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            v[i][j] = num++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // int arr2[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

    // int row = 4;
    // int col = 3;
    // int **arr = new int *[row];
    // for (int i = 0; i < row; i++)
    // {
    //     arr[i] = new int[col];
    // }
    // int num = 10;
    // // Insertion in 2D array
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         arr[i][j] = num++;
    //     }
    // }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}