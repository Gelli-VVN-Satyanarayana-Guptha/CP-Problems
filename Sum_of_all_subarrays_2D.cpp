// Program to find the sum of all subarrays of a 2D array

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += (i+1)*(j+1)*(n-i)*(m-j)*arr[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}