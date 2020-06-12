// dfs 4 direction, find connected component
// and left and right are same.


#include<bits/stdc++.h>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char g[55][55];
bool vis[55][55];
int x, y, m, n;
int dfs(int cx, int cy, char c){
    cy = (cy+n)%n;
    if(cx < 0 || cx >= m || g[cx][cy] != c || vis[cx][cy]) return 0;
    vis[cx][cy] = 1;
    int res = 1;
    for(int k = 0; k<4; ++k){
        res += dfs(cx+dir[k][0], cy + dir[k][1], c);    
    }
    return res;
}

int main()
{
    while(cin >> m >> n){
        memset(vis, 0, sizeof vis);
        for(int i = 0; i< m; ++i)
            for(int j =0; j <n; ++j)
                cin >> g[i][j];
        cin >> x >> y;
        char c = g[x][y];
        dfs(x, y, c);
        int mx = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(g[i][j] == c && !vis[i][j]){
                    mx = max(mx, dfs(i, j, c));
                }
            }    
        }
        cout << mx << "\n"; 
    }
}
