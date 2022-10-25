#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int TC;
    cin>>TC;
    while(TC--){
        int m,n;
        cin>>m>>n;
        vector<vector<int>> grid(m, vector<int>(n,0));
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int t;
                cin>>t;
                grid[i][j] = t;
                if(t == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                if(t == 1){
                    count++;
                }
            }
        }
        int ans = 0;
        int cnt = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            ans = max(ans,time);
            q.pop();
            int drow[] = {1,-1,0,0};
            int dcol[] = {0,0,1,-1};
            for(int k = 0 ; k < 4 ; k++){
                int nr = row + drow[k];
                int nc = col + dcol[k];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && vis[nr][nc] == 0){
                    q.push({{nr,nc},time+1});
                    vis[nr][nc] = 1;
                    cnt++;
                }
            }
        }

        if(count != cnt){
            ans = -1;
        }
        cout<<ans<<"\n";
    }
}