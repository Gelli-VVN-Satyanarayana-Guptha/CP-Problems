// Fibonacci sequence using Recursion, Dynamic Programming and Matrix Exponentiation
// Fibonacci sequence: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 ......


#include <bits/stdc++.h>
using namespace std;

// Helper functions for Matrix Exponentiation
// Matrix Multiplication
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B){
    int k = A.size();
    vector<vector<int>> res(k, vector<int>(k, 0));
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            for(int x=0; x<k; x++){
                res[i][j] += A[i][x] * B[x][j];
            }
        }
    }
    return res;
}

// Power of Matrix
vector<vector<int>> power(vector<vector<int>> T, int n){
    vector<vector<int>> res(T.size(), vector<int>(T.size(), 0));
    // Making the identity matrix
    for(int i=0; i<T.size(); i++){
        res[i][i] = 1;
    }

    vector<vector<int>> temp = T;
    while(n>0){
        if(n&1){
            res = multiply(res, temp);
        }
        temp = multiply(temp, temp);
        n >>= 1;
    }
    return res;
}

// Using Recusion
// Time Complexity: O(2^n)
// Space Complexity: O(1)
// Max value of n = 25
int fiboRecursion(int n){
    if(n==0 || n==1){
        return n;
    }
    return fiboRecursion(n-1)+fiboRecursion(n-2);
}

// Using Dynamic Programming 
// Top Down Approach - Recursion
// Time Complexity: O(n)
// Space Complexity: O(n)
// Max value of n = 10^8
int fiboTopDown(int n, vector<int> &dp){
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = fiboTopDown(n-1, dp) + fiboTopDown(n-2, dp);
    dp[n] = ans;
    return ans;
}

// Using Dynamic Programming
// Bottom Up Approach - Iteration
// Time Complexity: O(n)
// Space Complexity: O(1)
// Max value of n = 10^8
void fiboBottomUp(int n){
    int first = 0;
    int second = 1;
    cout<<first<<" ";
    cout<<second<<" ";
    for(int i=2; i<=n; i++){
        int temp = first + second;
        first = second;
        second = temp;
        cout<<second<<" ";
    }
}

// Advanced Matrix Exponentiation
// Time Complexity: O(k^3 * logn)
// Space Complexity: O(1)
// Max value of n = 10^18
void fiboME(int n){
    int k = 2;
    // Making the transformation matrix
    vector<vector<int>> T(k, vector<int>(k, 0));
    for(int i = 0;i<k-1;i++){
        for(int j = 0;j<k;j++){
            if(i==j){
                T[i][j+1] = 1;
            }
        }
    }
    T[k-1][0] = 1;
    T[k-1][1] = 1;

    // Making the vector F0
    vector<vector<int>> y0(k, vector<int>(1, 0));
    y0[0][0] = 0;
    y0[1][0] = 1;

    // Matrix Multiplication
    vector<vector<int>> powerMat = power(T, n-1);
    vector<vector<int>> res =  multiply(powerMat, y0);

    // Printing the result
    cout<<res[k-1][0]<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    cout<<"Fibonacci sequence using Recursion: "<<endl;
    for(int i=0; i<=n; i++){
        cout<<fiboRecursion(i)<<" ";
    }
    cout<<endl;

    cout<<"Fibonacci sequence using Top Down Approach: "<<endl;
    fiboTopDown(n, dp);
    for(int i=0; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    cout<<"Fibonacci sequence using Bottom Up Approach: "<<endl;
    fiboBottomUp(n);
    cout<<endl;

    cout<<"Fibonacci sequence using Matrix Exponentiation: ";
    fiboME(n);
    cout<<endl;
      
    return 0;
}
