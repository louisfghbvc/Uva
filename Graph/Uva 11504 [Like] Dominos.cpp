// Nice problem scc. O(N+E)
// after compress then a new dag.


#include <bits/stdc++.h> // 11504
#define N 100005
using namespace std;

vector<int> g[N];
int low[N], dfn[N], cur;
bool ind[N];
int sc[N], id;
stack<int> st;
bool inst[N];

void dfs(int u){
    low[u] = dfn[u] = ++cur;
    inst[u] = true;
    st.push(u);
    for(auto &v: g[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inst[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(low[u] == dfn[u]){
        int nxt;
        id++;
        do{
            nxt = st.top(); st.pop();
            inst[nxt] = 0;
            sc[nxt] = id;

        }while(nxt != u);
    }
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int t, n, m;
    cin >> t;
    while(t--){
        while(!st.empty()) st.pop();
        memset(inst, 0, sizeof inst);
        memset(low, 0, sizeof low);
        memset(dfn, 0, sizeof dfn);
        memset(ind, 0, sizeof ind);
        memset(sc, 0, sizeof sc);
        cur = id = 0;

        cin >> n >> m;
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }

        for(int i = 1; i <= n; ++i){
            if(!dfn[i]) dfs(i);
        }

        for(int u = 1; u <= n; ++u){
            for(auto &v: g[u]){
                if(sc[u] != sc[v])
                    ind[sc[v]] = 1;
            }
        }

        int ans = 0;
        for(int i = 1; i <= id; ++i){
            if(!ind[i]) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
/**
1
5 4
1 2
2 3
1 3
5 1
**/
