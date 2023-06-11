#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int arr[n];
    int prefix[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        if(i % 2 == 0)
        prefix[i] = prefix[i-1] + arr[i];
        else
        prefix[i] = prefix[i-1];
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        if(l == 0){
            cout << prefix[r] << endl;
        }
        else{
            cout << prefix[r] - prefix[l-1] << endl;
        }
    }
    

    return 0;
}