// eight direction dfs.

#include <bits/stdc++.h>
#define N 55
using namespace std;

char g[N][N];
int m, n, t, k;
const int dir[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
bool dfs(int x, int y, int kk, string& s, int c){
	if(c == s.size()) return 1;
	if(x < 0 || x >= m || y < 0 || y >= n || s[c] != g[x][y]) return 0;
	return dfs(x+dir[kk][0], y+dir[kk][1], kk, s, c+1);
}

int main(){
    cin >> t;
    while(t--){
    	cin >> m >> n;
    	for(int i = 0; i < m; ++i)
    		for(int j = 0; j < n; ++j) cin >> g[i][j], g[i][j] = tolower(g[i][j]);
    	cin >> k;
    	string str;
    	while(k--){
    		cin >> str;
    		for(int i = 0; i < str.size(); ++i) str[i] = tolower(str[i]);
    		for(int i = 0; i < m; ++i){
    			for(int j = 0; j < n; ++j){
    				if(g[i][j] != str[0]) continue;
    				for(int kk = 0; kk < 8; ++kk){
    					if(dfs(i, j, kk, str, 0)){
    						printf("%d %d\n", i+1, j+1);
    						i = 100, j = 100; break;
    					}
    				}
    			}
    		}
    	}
    	if(t) puts("");
    }
    return 0;
}
