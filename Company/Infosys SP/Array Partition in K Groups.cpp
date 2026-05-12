#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int N;
int solve(int i,vector<int>&nums, int k){
    if(i == N){
        //reached last ->
        return k==0?0:INT_MIN;
    }
    if(k==0){
        //not reached till last -> but k early 0 
        return -1e9;
    }
    if (k > N - i) return -1e9;

    int score = 0;
    unordered_map<int,int>mp;
    int maxF = 0;

    for(int group = i; group <= N-k ; group++ ){
            mp[nums[group]]++;
            maxF = max(maxF, mp[nums[group]]);        
            score = max(score, maxF + solve(group+1, nums,k-1));
    }
    return score;
}





int getMaxScore(vector<int>&nums, int k){
    int n = nums.size();
    vector<vector<int>>dp(n +1,vector<int>(k+1,0));

    // dp[i][j] ->  (0 --> i-1) tak elemets se j partions banne pe maximum ->score 


    for(int i=1;i<=n;i++){
        unordered_map<int,int>mp;
        int maxF = 0;
        for(int j=1;j<=k && j<=i;j++){
            mp[nums[j]]++;
            maxF = max(maxF, mp[nums[j]]);        
            dp[i][j] = max(dp[i][j], maxF + dp[i][k-1]);
        }
    }

    
    return dp[n][k];
}



int main(){
    int n,k;
    cin>>n>>k;

    vector<int>nums(n,0);
    

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<getMaxScore(nums,k);
}