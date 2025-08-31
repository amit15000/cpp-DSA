#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printPattern(vector<int>arr){
    int maxElement = *max_element(arr.begin(),arr.end());
    int minElement = *min_element(arr.begin(), arr.end());

    for(int i = maxElement; i>=minElement ; i--){
        cout<<i<<"\t";
        for(int val : arr){
            if(i==val){
                cout<<"*\t";
            }
            else{
                cout<<"\t";
            }
        }
        cout<<endl;
    }

}



int main(){
    vector<int>arr = {0,3,2,-3,5,-2,2,-5};

    printPattern(arr);
    return 0;
}