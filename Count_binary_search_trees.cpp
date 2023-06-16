// count the number of binary search trees that can be formed with n nodes

#include <bits/stdc++.h>
using namespace std;

// Recursive approach
// Time complexity: O(n^n)
int countBstRec(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += countBstRec(i - 1) * countBstRec(n - i);
    }
    return ans;
}

// Top down approach
// Time complexity: O(n^2)
int countBstTopDown(int n, int dp[])
{
    if (dp[n] != -1)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += countBstTopDown(i - 1, dp) * countBstTopDown(n - i, dp);
    }
    return dp[n] = ans;
}

// Bottom up approach
// Time complexity: O(n^2)
int countBstBottomUp(int n){
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 0;
        for(int j=1; j<=i; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

// Catalan number approach
// Time complexity: O(n)

long long fact(int n){
    long long ans = 1;
    for(int i=2; i<=n; i++){
        ans *= i;
    }
    return ans;
}

int catalan(int n){
    int res = fact(2*n)/(fact(n+1)*fact(n));
    return res;
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Number of BSTs using Recursion: "<<countBstRec(n)<<"\n";
    int dp[n+1];
    fill_n(dp, n+1, -1);
    dp[0] = dp[1] = 1;
    cout<<"Number of BSTs using Top Down approach: "<<countBstTopDown(n, dp)<<"\n";
    cout<<"Number of BSTs using Bottom Up approach: "<<countBstBottomUp(n)<<"\n";
    cout<<"Number of BSTs using Catalan number approach: "<<catalan(n)<<"\n";
    return 0;
}