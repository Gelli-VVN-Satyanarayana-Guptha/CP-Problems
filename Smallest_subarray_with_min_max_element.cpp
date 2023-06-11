/* Program to find the smallest subarray with minimum and maximum element in an array
 having duplicate elements */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int max_idx = -1;
    int min_idx = -1;
    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        int len = 0;
        if(arr[i] == mini){
            min_idx = i;
            if(max_idx != -1){
                len = min_idx - max_idx + 1;
                ans = min(ans, len);
            }
        }else if(arr[i] == maxi){
            max_idx = i;
            if(min_idx != -1){
                len = max_idx - min_idx + 1;
                ans = min(ans, len);
            }
        }
    }

    cout << ans << endl;

    return 0;
}