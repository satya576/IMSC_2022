#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> &A){
    if(i == 0 && j == 0)
        return A[i][j];
    if(i < 0 || j < 0)
        return INT_MIN;
    return max(f(i-1, j, A), f(i, j-1, A)) + A[i][j];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m,n;
    cin>>m>>n;
    vector<vector<int>> A;
    int val;
    for(int i = 0; i < m; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            cin>>val;
            row.push_back(val);
        }
        A.push_back(row);
    }
    cout<<f(m-1, n-1, A)<<"\n";
}