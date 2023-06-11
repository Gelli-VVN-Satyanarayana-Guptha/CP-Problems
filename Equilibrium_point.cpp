#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int prefix[n];
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    for(int i = 0; i < n; i++){

        int left, right;

        if(i == 0){
            left = 0;
            right = prefix[n-1] - prefix[i];
        }
        else if(i == n-1){
            left = prefix[i-1];
            right = 0;
        }
        else{
            left = prefix[i-1];
            right = prefix[n-1] - prefix[i];
        }

        if(left == right){
            cout << i << endl;
        }
    }
    return 0;
}