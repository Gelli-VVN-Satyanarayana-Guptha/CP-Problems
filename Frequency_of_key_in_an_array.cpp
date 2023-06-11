// Program to find the frequency of given key in aa array

#include <bits/stdc++.h>
using namespace std;

void  freq_binary_search(int arr[], int n, int key){

    int low = 0, high = n-1, mid, first, last;

    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == key){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    low = 0, high = n-1;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == key){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << last - first + 1 << endl;
}

void freq_stl(int arr[], int n, int key){
    int *low = lower_bound(arr, arr+n, key);
    int *high = upper_bound(arr, arr+n, key);
    cout << high - low << endl;
}

int main(){
    int n, key;
    cin >> n >> key;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    freq_binary_search(arr, n, key);
    freq_stl(arr, n, key);
    
    return 0;
}