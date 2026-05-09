#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<2> bs(18);
    cout<<bs<<endl;

    int num = 5;
    int bits = __builtin_popcount(5);
    cout<<bits<<endl;
    // Set 1st bit
    // bs.set(0);
    // cout << bs << endl;
    
    // // Reset 2nd bit 
    // bs.reset(1);
    // cout << bs << endl;
    
    // // Flip 5th bit
    // bs.flip(4);
    // cout << bs;
    return 0;
}