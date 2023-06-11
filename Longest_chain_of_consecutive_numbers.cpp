// Find the length of longest chain of consecutive numbers in the given array

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i]-1) == s.end()){
            int j = arr[i];
            while(s.find(j) != s.end()){
                j++;
            }
            ans = max(ans,j-arr[i]);
        }
    }
    cout << ans <<endl;
    return 0;
}