// Find the smallest element in a k rotated sorted array using binary search

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] > arr[high]){
            low = mid + 1;
        }
        else if(arr[mid] < arr[high]){
            high = mid;
        }
        else{
            cout << arr[mid] << endl;
            break;
        }
    }
    return 0;
}