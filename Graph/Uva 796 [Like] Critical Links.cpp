// Just tarjan's algorithm god think.
// O(N).


#include <bits/stdc++.h>
#define N 5005
using namespace std;
vector<int> g[N];
int low[N], dfn[N], t;
vector<pair<int, int>> cp;

void dfs(int u, int p){
    low[u] = dfn[u] = ++t; 
    for(auto &v: g[u]){
        if(v == p) continue;
        if(!low[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                if(u < v) cp.push_back({u, v});
                else cp.push_back({v, u});
            }
        }
        else{
            low[u] = min(dfn[v], low[u]);
        }
    }
}

int main()
{
    int n, u, e, v;
    while(cin >> n){

        for(int i = 0; i < n; ++i) g[i].clear();
        for(int i = 0; i < n; ++i){
            cin >> u;
            scanf(" (%d) ", &e);
            for(int j = 0; j < e; ++j){
                cin >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        memset(low, 0, sizeof low);
        memset(dfn, 0, sizeof dfn);
        cp.clear();
        t = 0;
        for(int i = 0; i < n; ++i){
            if(!low[i])  dfs(i, -1);
        }
        sort(cp.begin(), cp.end());
        printf("%d critical links\n", (int)cp.size());
        for(auto &p : cp){
            cout << p.first << " - " << p.second << endl;
        }
        puts("");
    }
}
