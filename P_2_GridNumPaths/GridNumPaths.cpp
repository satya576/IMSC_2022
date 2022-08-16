#include<bits/stdc++.h>
using namespace std;
int f(int i, int j){
    if(i == 0 || j == 0)
        return 1;
    return f(i-1,j) + f(i, j-1);
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<f(m,n)<<"\n";
}