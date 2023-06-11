/* Ramu need to divide a plot into 4 parts and ramu will get the 
plot which has least trees.
Maximize the minimum number of trees ramu can get. */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) 
        cin >> arr[i][j];
    }

    // 2D prefix sum array
    int prefix[n][m];
    prefix[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j];
        }
    }

    // To maximize the number of trees in the plot which ramu will get
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            int q1 = prefix[i][j];
            int q2 = prefix[i][m-1] - q1;
            int q3 = prefix[n-1][j] - q1;
            int q4 = prefix[n-1][m-1] - q1 - q2 - q3;
            
            int mini = min(q1, min(q2, min(q3, q4)));
            ans = max(ans, mini);
        }
    }
    cout << ans << endl;

    return 0;
}