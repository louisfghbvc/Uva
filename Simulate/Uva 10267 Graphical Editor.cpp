// Just implement,
// care y1, y2 range maybe inversed.
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> g;
int m, n;
char color;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y, char c, char nc){
	if(c == nc) return;
	g[x][y] = nc;
	for(int k = 0; k < 4; ++k){
		int nx = x+dir[k][0], ny = y+dir[k][1];
		if(nx <= 0 || ny <= 0 || nx > n || ny > m || g[nx][ny] != c) continue;
		dfs(nx, ny, c, nc);
	}
}

int main(){
	char c;
    while(cin >> c && c != 'X'){
   		int x1, y1, x2, y2;
    	string name;
    	switch(c){
    		case 'I':
    			cin >> m >> n;
    			g = vector<vector<char>>(n+1, vector<char>(m+1, 'O'));
    			break;
    		case 'C':
    			g = vector<vector<char>>(n+1, vector<char>(m+1, 'O'));
    			break;
    		case 'L':
    			cin >> x1 >> y1 >> color;
    			g[y1][x1] = color;
    			break;
    		case 'V':
    			cin >> x1 >> y1 >> y2 >> color;
    			if(y1 > y2) swap(y1, y2);
    			for(int i = y1; i <= y2; ++i)
    				g[i][x1] = color;
    			break;
    		case 'H':
    			cin >> x1 >> x2 >> y1 >> color;
    			if(x1 > x2) swap(x1, x2);
    			for(int j = x1; j <= x2; ++j)
    				g[y1][j] = color;
    			break;
    		case 'K':
    			cin >> x1 >> y1 >> x2 >> y2 >> color;
    			if(y1 > y2) swap(y1, y2);
    			if(x1 > x2) swap(x1, x2);
    			for(int j = x1; j <= x2; ++j)
    				for(int i = y1; i <= y2; ++i)
    					g[i][j] = color;
    			break;
    		case 'F':
    			cin >> x1 >> y1 >> color;
				dfs(y1, x1, g[y1][x1], color);
    			break;
    		case 'S':
    			cin >> name;
    			cout << name << endl;
    			for(int i = 1; i <= n; ++i){
    				for(int j = 1; j <= m; ++j)
    					cout << g[i][j];
    				cout << endl;
    			}
    			break;
    		defalut:
    			string tm;
    			getline(cin, tm);
    			break;
    	}
    }
    return 0;
}
