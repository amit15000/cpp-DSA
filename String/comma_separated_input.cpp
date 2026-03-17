#include<iostream>
#include<sstream>
#include<string>
#include<vector>


using namespace std;

int main(){
    string s;

    getline(cin, s);

    stringstream ss(s);
    string num;
    vector<int>arr;

    while(getline(ss, num, ',')){
        int n = stoi(num);
        arr.push_back(n);
    }

    for(auto n : arr){
        cout<<n<<" ";
    }
    return 0;
}