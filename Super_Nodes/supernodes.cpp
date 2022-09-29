#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void DFS(vi adj[], vi &visited, int s, int n){
    visited[s] = 1;
    for(auto i : adj[s]){
        if(visited[i] == -1)
            DFS(adj, visited, i, n);
    }
}

void superNode(vi adj[], vi &revisit, int s, int n, int A){
    revisit[s] = 1;
    for(auto i : adj[s]){
        if(revisit[i] == -1 && i != A)
            superNode(adj, revisit, i, n, A);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vi adj[n];  // adj = [[1,3],[2,4],[2]]
    int u;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>u;
            if(u != 0){
                adj[i].push_back(j);
            }
        }
    }

    vi visited(n, -1);
    DFS(adj, visited, 0, n);

    for(int  i = 0 ; i<n ; i++){
        if(visited[i] == -1)
            cout<<" N";
        else
            cout<<" Y";
    }
    cout<<"\n";
    for(int A = 1 ; A < n ; A++){
        vi revisit(n, -1);
        superNode(adj, revisit, 0, n, A);
        for(int j = 0 ; j < n ; j++){
            if(visited[j] != revisit[j])
                cout<<" Y";
            else
                cout<<" N";
        }
        cout<<"\n";
    }

}