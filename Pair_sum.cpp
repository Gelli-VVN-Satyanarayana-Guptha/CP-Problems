// Count the number of pairs in an array whose sum is equal to given number

#include <bits/stdc++.h>
using namespace std;

int pair_sum_unsorted_set(int arr[], int n, int sum){
    int count = 0;
    unordered_set<int> s;
    
    for(int i = 0 ; i < n ; i++){
        if(s.find(sum-arr[i]) != s.end()){
            count++;
        }
        s.insert(arr[i]);
    }
    return count;
}

int pair_sum_two_pointer(int arr[], int n, int sum){
    int count = 0;
    sort(arr, arr+n);
    int i = 0, j = n-1;
    while(i < j){
        if(arr[i]+arr[j] == sum){
            count++;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] < sum){
            i++;
        }
        else{
            j--;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum;
    cin>>sum;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    cout<<pair_sum_unsorted_set(arr, n, sum)<<endl;
    cout<<pair_sum_two_pointer(arr, n, sum)<<endl;

}