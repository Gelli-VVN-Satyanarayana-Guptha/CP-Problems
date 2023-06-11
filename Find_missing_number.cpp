// Find the missing number in the given array of size N and range of elements is 1 to N+1.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    int total = (n+1)*(n+2)/2;
    int missing = total - sum;
    
    cout<<missing<<endl;

    return 0;
}