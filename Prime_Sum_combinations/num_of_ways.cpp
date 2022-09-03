#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;


vi A;
// vvi DP1(5, vi(6));
// int i,n,k;
vvvi DP(500, vvi(1000, vi(15, -1)));

int f(int i, int n, int k){
    if(n == 0 && k == 0) return 1;
    if(n == 0 || i < -1) return 0;
    if(k > i+1) return 0;

    int Take = 0;
    if(A[i] <= n)
        Take = f(i - 1, n - A[i], k - 1);
    int notTake = f(i-1, n, k);
    return Take + notTake;
}

int f_DP(int i, int n, int k, vvvi &DP){
    if(n == 0 && k == 0) return 1;
    if(n == 0 || i < -1) return 0;
    if(k > i+1) return 0;
    if(DP[i][n][k] != -1) return DP[i][n][k];

    int Take = 0;
    if(A[i] <= n)
        Take = f_DP(i - 1, n - A[i], k - 1, DP);
    int notTake = f_DP(i-1, n, k, DP);
    return DP[i][n][k] = Take + notTake;
}


int main(){
    int n, k;
    cin>>n>>k;
    
    //// Exercise for finding prime numbers below n.
    //A.push_back(???);

    int size = A.size();
    cout<<f(size - 1, n, k)<<endl;
}