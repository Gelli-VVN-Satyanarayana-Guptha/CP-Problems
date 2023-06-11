// Print triplets having sum equal to a given value

#include <bits/stdc++.h>
using namespace std;

void triplet_sum_unordered_set(int arr[], int n, int sum){

    cout<<"Triplets using unordered set: "<<endl;

    for(int i = 0; i < n; i++){
        unordered_set<int> s;
        int curr_sum = sum - arr[i];
        for(int j = i+1; j < n; j++){
            if(s.find(curr_sum - arr[j]) != s.end()){
                cout << arr[i] << " " << arr[j] << " " << curr_sum - arr[j] << endl;
            }
            s.insert(arr[j]);
        }
    }
    
}

void triplet_sum_two_pointer(int arr[], int n, int sum){

    sort(arr, arr+n);

    cout<<"Triplets using two pointer: "<<endl;

    for(int i = 0; i < n-2; i++){
        int l = i+1;
        int r = n-1;
        while(l < r){
            if(arr[i] + arr[l] + arr[r] == sum){
                cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                l++;
                r--;
            }
            else if(arr[i] + arr[l] + arr[r] < sum){
                l++;
            }
            else{
                r--;
            }
        }
    }
}

int main(){
    int n, sum;
    cout << "Enter the size of array and sum: ";
    cin >> n >> sum;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    triplet_sum_unordered_set(arr, n, sum);
    triplet_sum_two_pointer(arr, n, sum);

    return 0;
}