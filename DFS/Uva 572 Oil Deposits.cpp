//Just DFS
#include <bits/stdc++.h>
#define N 105
using namespace std;
char grid[N][N];
bool vis[N][N];
const int dir[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
int m, n;
void dfs(int x, int y){
	if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || grid[x][y] == '*') return;
	vis[x][y] = 1;
	for(int i = 0; i < 8; ++i){
		dfs(x+dir[i][0], y+dir[i][1]);
	}
}

int main(){
    while(cin >> m >> n, m+n){
    	memset(vis, 0, sizeof vis);
    	for(int i = 0; i < m; ++i)
    		for(int j = 0; j < n; ++j)
    			cin >> grid[i][j];
    	int cnt = 0;
    	for(int i = 0; i < m; ++i){
    		for(int j = 0; j < n; ++j){
    			if(!vis[i][j] && grid[i][j] == '@')
    				dfs(i, j), cnt++;
    		}
    	}
    	cout << cnt << endl;
    }
    return 0;
}
