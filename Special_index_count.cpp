/* Special index is a index when we remove a index then the sum of elements at even index
is equal to the sum of elements at odd indexs */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    int even_prefix[n];
    int odd_prefix[n];
    for(int i = 0; i < n; i++){
        if(i == 0){
            even_prefix[i] = arr[i];
            odd_prefix[i] = 0;
        }
        else if(i % 2 == 0){
            even_prefix[i] = even_prefix[i-1] + arr[i];
            odd_prefix[i] = odd_prefix[i-1];
        }else {
            even_prefix[i] = even_prefix[i-1];
            odd_prefix[i] = odd_prefix[i-1] + arr[i];
        }
    }

    for(int i = 0; i < n; i++){
        int odd_sum = 0;
        int even_sum = 0;

        if(i == 0){
            odd_sum = even_prefix[n-1] - even_prefix[i];
            even_sum = odd_prefix[n-1];
        }else if(i == n-1){
            odd_sum = odd_prefix[n-2];
            even_sum = even_prefix[n-2];
        }else{
            odd_sum = odd_prefix[i-1] + even_prefix[n-1] - even_prefix[i];
            even_sum = even_prefix[i-1] + odd_prefix[n-1] - odd_prefix[i];
        }

        if(odd_sum == even_sum)
            cout << i << endl;
    }


    return 0;
}