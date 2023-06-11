// Rotation of a 2D array by 90 degrees

#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[4][4], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void transpose_matrix(int arr[4][4], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void rotate_array_clockwise(int arr[4][4], int n, int m){
    transpose_matrix(arr,n,m);
    for(int i = 0; i < n; i++){
        reverse(arr[i], arr[i]+m);
    }
}

void rotate_array_anticlockwise(int arr[4][4], int n, int m){
    transpose_matrix(arr,n,m);
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < m ; j++){
            swap(arr[i][j], arr[n-1-i][j]);
        }
    }
}

int main(){
    int n = 4, m = 4;
    int arr[4][4];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"The original array is: "<<endl;
    print_array(arr,n,m);

    cout<<"Array after 90 degree clockwise rotation: "<<endl;
    rotate_array_clockwise(arr,n,m);
    print_array(arr,n,m);

    cout<<"Array after 90 degree anticlockwise rotation: "<<endl;
    rotate_array_anticlockwise(arr,n,m);
    print_array(arr,n,m);

    return 0;
}

