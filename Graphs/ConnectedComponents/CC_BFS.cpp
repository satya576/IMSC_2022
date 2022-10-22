#include<bits/stdc++.h>
using namespace std;

int vis[100][100] = {0};

void BFS(int i, int j, int n, int m, vector<string> &Grid){
    vis[i][j] = 1;
    queue<pair<int, int>> Q;
    Q.push({i,j});
    int dx[] = {-1, -1, 0,1, 1,1,0,-1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    
    while(!Q.empty()){
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for( int k = 0 ; k < 8 ; k++){
            int nr = r + dx[k];
            int nc = c + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && Grid[nr][nc] == '@' && vis[nr][nc] == 0){
                vis[nr][nc] = 1;
                Q.push({nr, nc});
            }
        }
    }

}


int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin>>n>>m;
    //cout<<n<<" "<<m;
    vector<string> Grid;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin>>str;
        Grid.push_back(str);
    }
    //cout<<Grid[0]<<"\n";
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(Grid[i][j] == '@' && vis[i][j] == 0 ){
                count++;
                BFS(i, j, n, m, Grid);
            }
        }
    }

   cout<<count<<"\n";

}