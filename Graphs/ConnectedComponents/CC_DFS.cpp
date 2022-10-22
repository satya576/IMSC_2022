#include<bits/stdc++.h>
using namespace std;
typedef vector<int, vector<int>> vii;

int vis[100][100] = {0};

void DFS(int i, int j, int m, int n, vector<string> &Grid){
    vis[i][j] = 1;
    int dx[] = {-1, -1, 0,1, 1,1,0,-1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    for(int k = 0 ; k < 8 ; k++){
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        if( new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && Grid[new_i][new_j] == '@' && vis[new_i][new_j] == 0){
            DFS(new_i, new_j, m, n, Grid);
        }
    }
 }


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n; // 1 <= m,n <= 100
    cin>>m>>n;
    int count = 0 ;
    vector<string> Grid;
    for(int i = 0 ; i < m ; i++){
        string temp;
        cin>>temp;
        Grid.push_back(temp);
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(Grid[i][j] == '@' && vis[i][j] == 0){
                count++;
                DFS(i,j, m, n, Grid);
            }
        }
    }
    cout<<count<<"\n";
}