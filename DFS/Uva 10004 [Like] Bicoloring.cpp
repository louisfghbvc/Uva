//just dfs. try to color all node, if visited and color are same then false
#include <bits/stdc++.h>
#define N 205
using namespace std;

vector<int> g[N];
int color[N];
bool ok = true;

void dfs(int u, int p, int c){
    
    if(!color[u])
        color[u] = 3 - c;
    //cout << u << " " << color[u] << endl;
    
    for(auto v: g[u]){
        if(v == p) continue;
        if(color[v] && color[v] == color[u]) ok = false;
        if(!color[v]){
            dfs(v, u, color[u]);
        }
    }
}

int main()
{
    int n, m;
    while(cin >> n, n){
        for(int i = 0; i < n; ++i) g[i].clear();
        memset(color, 0, sizeof color);
        cin >> m;
        for(int i = 0; i < m; ++i){
           int a, b;
           cin >> a >> b;
           g[a].push_back(b);
           g[b].push_back(a);
        }
        
        ok = true;
        dfs(0, -1, 2);
        puts(ok ? "BICOLORABLE." : "NOT BICOLORABLE.");
       
    }
    return 0;
}
