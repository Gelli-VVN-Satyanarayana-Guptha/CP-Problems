// Program to find the square root of a number up to 3 decimal places

#include <bits/stdc++.h>
using namespace std;

float sqrt(int n){
    int s = 0,e = n;
    float ans;
    while(s <= e){
        int mid = (s+e)/2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid < n){
            s = mid+1;
            ans = mid;
        }
        else{
            e = mid-1;
        }
    }
    float inc = 0.1;
    for(int i = 0;i < 3; i++){
        while(ans*ans <= n){
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Square root: "<<sqrt(n)<<endl;
}