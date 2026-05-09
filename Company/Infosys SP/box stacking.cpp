#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int &n, vector<int>&W, vector<int>&H){
    unordered_map<int,long long>base;
    for(int i=0;i<W.size();i++){
        base[W[i]] = max(base[W[i]],(long long) H[i]);
    }
    long long ans = 0;
    for(auto &[w,h] : base){
        ans += max(0LL,h);
    }
    return ans;
}



int main(){
    int n;
    cin>>n;

    vector<int>W(n,0);
    vector<int>H(n,0);

    for(int i=0;i<n;i++){
        cin>>W[i];
    }
    for(int i=0;i<n;i++){
        cin>>H[i];
    }


    cout<<solve(n,W,H);
}