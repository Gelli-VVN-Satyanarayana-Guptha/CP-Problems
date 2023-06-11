// Rotate the given 1 D array by k times in clockwise direction

#include <bits/stdc++.h>
using namespace std;

void rotate_clockwise(int arr[],int n, int k){
    reverse(arr, arr+n-k);
    reverse(arr+n-k, arr+n);
    reverse(arr, arr+n);
}

void rotate_anticlockwise(int arr[],int n, int k){
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
}

void print_array(int arr[], int n){
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n, k;
    cout<<"Enter the size of array: "<<endl;
    cin >> n ;
    cout<<"Enter the number of rotations: "<<endl;
    cin >> k;

    k = k % n;
    int arr[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0; i<n; i++) cin >> arr[i];

    cout<<"Original Array: "<<endl;
    print_array(arr, n);

    cout<<"Clockwise Rotation: "<<endl;
    rotate_clockwise(arr, n, k);
    print_array(arr, n);

    cout<<"Anti-Clockwise Rotation: "<<endl;
    rotate_anticlockwise(arr, n, k);
    print_array(arr, n);

    return 0;
}