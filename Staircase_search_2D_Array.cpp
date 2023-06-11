// Stairecase Search is used when only the rows and columns are sorted in a 2D Array

#include <bits/stdc++.h>
using namespace std;

// Staircase Search in 2D Array
// Time Complexity: O(n+m)
// Space Complexity: O(1)

void staitcase_search(vector<vector<int>> arr,int x,int n,int m){
    int row = 0,column = m-1;
    while(row<n && column>=0){
        if(arr[row][column]==x){
            cout<<"Element found at index: ("<<row<<","<<column<<")"<<endl;
            return;
        }
        else if(arr[row][column] > x){
            column--;
        }
        else{
            row++;
        }
    }
    cout<<"Element not found"<<endl;
    return;
}

int main(){
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of columns: ";
    cin>>m;
    cout<<"Enter the element to be searched: ";
    int x;
    cin>>x;
    cout<<endl;
    vector<vector<int>> arr;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        arr.push_back(v);
    }

    cout<<"output: "<<endl;
    staitcase_search(arr,x,n,m);

    return 0;
}