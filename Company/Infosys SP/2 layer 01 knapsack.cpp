#include<bits/stdc++.h>
using namespace std;


int solve(int capacity , vector<int>&w1 , vector<int>&v1, vector<int>&w2, vector<int>&v2 ){

    vector<int>dp(capacity+1, 0);

    for(int i=1;i<=w1.size();i++){
        for(int cap = capacity ; cap >= w1[i-1] || cap >= w2[i-1] ; cap--){
            if(cap >= w1[i-1])
                dp[cap] = max(dp[cap], dp[cap - w1[i-1]] + v1[i-1]);
                //we can take or skip ith object from the layer1
            if(cap >= w2[i-1])
                dp[cap] = max(dp[cap], dp[cap - w2[i-1]] + v2[i-1]);
        }
    }
    return dp[capacity];
}


int main(){

}