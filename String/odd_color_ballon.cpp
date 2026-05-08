#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;

    char ballons[n];

    for(int i=0;i<n;i++){
        cin>>ballons[i];
    }


    map<char,int>freq;

    for(char color : ballons){
        freq[color]++;
    }

    for(auto it : freq){
        if(it.second & 1){
            //if odd count of the color
            cout<<it.first<<endl;
            return 0;
        }
    }

    cout<<"All are Even"<<endl;

    return 0;
}