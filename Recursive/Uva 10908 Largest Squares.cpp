// dfs, must has ans 1. check edge
#include <bits/stdc++.h>
#define N 105
using namespace std;

char grid[N][N];
int t, m, n, q, r, c;

bool check(int l){
    if(r-1 < 0 || r+l >= m || c-l < 0 || c+l >= n) return 0;
    for(int i = r-l; i <= r+l; ++i){
        for(int j = c-l; j <= c+l; ++j){
            if(grid[r][c] != grid[i][j]) return 0;
        }   
    }
    return 1;
}

int main()
{
    
    cin >> t;
    while(t--){
        cin >> m >> n >> q;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                cin >> grid[i][j];
        printf("%d %d %d\n", m, n, q);
        
        for(int i = 0; i < q; ++i){
            cin >> r >> c;
            int k = 3;
            while(check(k/2)) k+=2;
            cout << k-2 << endl;
        }
        
    }
}
