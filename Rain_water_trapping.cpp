// calculate the amount of water that can be trapped in between the blocks 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of blocks: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the height of the blocks: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left[n],right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for(int i = 1; i < n; i++){
        left[i] = max(left[i-1],arr[i]);
    }
    for(int i = n-2; i >= 0; i--){
        right[i] = max(right[i+1],arr[i]);
    }

    // To calculate the amount of water that can be trapped
    int water = 0;
    for(int i = 0; i < n; i++){
        water += min(left[i],right[i]) - arr[i];
    }
    cout<<"The amount of water that can be trapped is: "<<water<<endl;
    return 0;
}