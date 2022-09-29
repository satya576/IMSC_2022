#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(auto it : adj){
        for(auto e : it)
        cout<<e<<" ";
        cout<<"\n";
    }

    
}