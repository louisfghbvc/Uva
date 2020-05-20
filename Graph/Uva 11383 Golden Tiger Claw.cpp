// Maximum Weight Perfect Bipartite Matching.
// KM Algorithm
#include <bits/stdc++.h>
#define N 505
using namespace std;

int adj[N][N];
bool vx[N], vy[N];
int lx[N], ly[N], mx[N], my[N];
int n;

bool dfs(int x){
    vx[x] = 1;
    for(int y = 0; y < n; ++y)
        if(!vy[y] && adj[x][y] == lx[x] + ly[y]){
            vy[y] = 1;
            if(my[y] == -1 || dfs(my[y])){
                mx[x] = y; my[y] = x;
                return 1;
            }
        }
    return 0;
}

int KM(){
    memset(mx, -1, sizeof mx);
    memset(my, -1, sizeof my);
    memset(lx, 0, sizeof lx);
    memset(ly, 0, sizeof ly);
    for(int x = 0; x < n; ++x)
        for(int y = 0; y < n; ++y)
            lx[x] = max(lx[x], adj[x][y]);

    for(int x = 0; x < n; ++x)
        while(1){
            memset(vx, 0, sizeof vx);
            memset(vy, 0, sizeof vy);
            if(dfs(x)) break;

            int d = 1e9;
            for(int x = 0; x < n; ++x) if(vx[x])
                for(int y = 0; y < n; ++y) if(!vy[y])
                    d = min(d, lx[x] + ly[y] - adj[x][y]);

            for(int x = 0; x < n; ++x) if(vx[x])
                lx[x] -= d;

            for(int y = 0; y < n; ++y) if(vy[y])
                ly[y] += d;
        }

    int w = 0;
    for(int x = 0; x < n; ++x)
        printf("%d%c", lx[x], x == n-1 ? '\n' : ' '), w += lx[x];
    for(int y = 0; y < n; ++y)
        printf("%d%c", ly[y], y == n-1 ? '\n' : ' '), w += ly[y];
    return w;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    while(cin >> n){
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> adj[i][j];
        int ans = KM();
        printf("%d\n", ans);
    }
    return 0;
}
/**
2
1 1
1 1
**/
