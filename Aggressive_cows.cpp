// Aggressive Cows

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int cows,int dist){
    int count = 1, coordinate = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - coordinate >= dist){
            count++;
            coordinate = arr[i];
        }
    }
    return count >= cows;
}
void aggrcow(){
    int n, c;
    cin >> n >> c;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int low = 0, high = arr[n-1], ans = 0;
    while(low <= high){
        int mid = (low + high)/2;
        if(isPossible(arr, n, c, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
}
int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        aggrcow();
    }
    return 0;
}