// Matrix Multiplication
// Time Complexity: O(n^3)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_multiplication(vector<vector<int>> &mat1, vector<vector<int>> &mat2){
    int n = mat1.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            int a = 0;
            for(int k=0; k<n; k++){
                a += mat1[i][k] * mat2[k][j];
            }
            temp.push_back(a);
        }
        ans.push_back(temp);
    }
    return ans;
}

void print(vector<vector<int>> &mat){
    int n = mat.size();
    cout<<"The resultant matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    cout<<"Enter the elements of matrix 1: "<<endl;
    vector<vector<int>> mat1;
    vector<vector<int>> mat2;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            int t = 0;
            cin>>t;
            temp.push_back(t);
        }
        mat1.push_back(temp);
    }
    cout<<"Enter the elements of matrix 2: "<<endl;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            int t = 0;
            cin>>t;
            temp.push_back(t);
        }
        mat2.push_back(temp);
    }

    vector<vector<int>> ans = matrix_multiplication(mat1, mat2);
    print(ans);

    return 0;
}