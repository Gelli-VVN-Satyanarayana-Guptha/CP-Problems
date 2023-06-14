// Finding power of a number using recursion and iteration
// Time complexity: O(n) and O(logn) respectively

#include <bits/stdc++.h>
using namespace std;

// Iterative approach 
// Time complexity: O(n)
int powerIterativeLinear(int n, int p){
    int ans = 1;
    while(p--){
        ans *= n;
    }
    return ans;
}

// Recursive approach
// Time complexity: O(n)
int powerRecursionLinear(int n, int p){
    if(p == 0) return 1;
    return n * powerRecursionLinear(n, p-1);
}

// Recursive approach
// Time complexity: O(logn)
int powerRecursionLog(int n, int p){
    if(p == 0) return 1;
    int temp = powerRecursionLog(n, p/2);
    temp = temp*temp;
    if(p % 2 == 0) 
        return temp;
    else 
        return temp * n;
}

// Iterative approach
// Time complexity: O(logn)
// using the binary form of the power
int powerIterativeLog(int n, int p){
    int ans = 1;
    while(p > 0){
        if(p & 1){
            ans *= n;
        }
        n *= n;
        p = p >> 1;
    }
    return ans;
}

int main(){
    int n, p;
    cout<<"Enter the number: ";
    cin >> n;
    cout<<"Enter the power: ";
    cin >> p;
    cout<<"Iterative Linear: "<<powerIterativeLinear(n, p)<<"\n";
    cout<<"Iterative Log: "<<powerIterativeLog(n, p)<<"\n";
    cout<<"Recursive Linear: "<<powerRecursionLinear(n, p)<<"\n";
    cout<<"Recursive Log: "<<powerRecursionLog(n, p)<<"\n";

    return 0;
}