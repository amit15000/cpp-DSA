#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int prevGreat = arr[0];

    int res = 1;

    for(int i=1;i<n;i++){
        if(arr[i] > prevGreat){
            res++;
            prevGreat = arr[i];
        }
    }
    cout<<res;
    return 0;

}