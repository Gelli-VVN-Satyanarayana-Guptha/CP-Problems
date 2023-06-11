// count no of pairs i,j such that a[i] = 'a' and a[j] = 'g' and i < j

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 'a')
            count++;
        else if(arr[i] == 'g')
            sum += count;
    }

    cout << sum << endl;
    return 0;
}