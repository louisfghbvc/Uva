//Just Simulate. 8 direction sum
#include <bits/stdc++.h>

using namespace std;

char g[105][105], ans[105][105];
const int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

int main()
{
    int n, m, cas = 0;
    while(cin >> n >> m, n + m){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> g[i][j];    
            }
        }
        if(cas) puts("");
        printf("Field #%d:\n", ++cas);
        
        memset(ans, '0', sizeof ans);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j] == '*'){
                    ans[i][j] = '*';    
                }
                else{
                    for(int k = 0; k < 8; ++k){
                        int x = i+dir[k][0], y = j+dir[k][1];
                        if(x < 0 || x >= n || y < 0 || y >= m) continue;
                        if(g[x][y] == '*') ans[i][j]++;
                    }
                }
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}
