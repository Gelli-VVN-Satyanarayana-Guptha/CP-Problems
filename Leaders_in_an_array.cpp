#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int maxi = arr[n-1];
    int count = 1;
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > maxi){
            maxi = arr[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}