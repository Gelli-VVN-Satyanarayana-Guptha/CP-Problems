// Maximize the minimum sum of a partition of an array into k subarrays

#include <bits/stdc++.h>
using namespace std;

bool cangive(int arr[], int n, int k, int mid){
    int sum = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(sum < mid){
            sum += arr[i];
        }else{
            cnt++;
            sum = arr[i];
        }
    }
    if(sum >= mid){
        cnt++;
    }
    return cnt >= k;
}

int main(){
    int n, k;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the no of partitions: ";
    cin>>k;
    int arr[n];
    int sum = 0;
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    int start = 0;
    int end = sum;
    int ans = 0;

    while (start <= end){
        int mid = (start + end)/2;

        if(cangive(arr, n, k, mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout<<"The maximum sum of a partition of an array into k subarrays is: "<<ans<<endl;
    
    return 0;
}