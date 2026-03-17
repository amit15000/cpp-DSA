#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    string s;
    getline(cin, s);

    vector<int>arr;

    stringstream ss(s);

    string num;

    while(getline(ss, num, ' ')){
        if (num.empty()) continue;        ///added to skip "" empty spaces , leading , trailing or in b/w empty strings
        arr.push_back(stoi(num));
    }

    for(int ans : arr){
        cout<<ans;
    }
    cout<<endl;

    return 0;
}

