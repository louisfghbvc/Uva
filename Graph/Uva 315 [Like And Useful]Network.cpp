#include <bits/stdc++.h>
#define N 105
using namespace std;
vector<int> g[N];
int dfn[N], low[N], t;
bool Ap[N];

void dfs(int u, int p){
    dfn[u] = low[u] = ++t;
    int child = 0;

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == p) continue;
        if(!dfn[v]){
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if((p == -1 && child > 1) || (p != -1 && low[v] >= dfn[u]))
                Ap[u] = true;
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int n;
    string s;
    while(cin >> n, n){
        cin.ignore();
        for(int i = 1; i <= n; ++i)
            g[i].clear();
       while(getline(cin, s)){
            if(s == "0") break;
            stringstream ss(s);
            int a, b;
            ss >> a;
            while(ss >> b){
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }

        memset(Ap, 0, sizeof Ap);
        memset(low, 0, sizeof low);
        memset(dfn, 0, sizeof dfn);
        t = 0;

        for(int i = 1; i <= n; ++i){
            if(!dfn[i]){
                dfs(i, -1);
            }
        }

        int res = 0;
        for(int i = 1; i <= n; ++i)
            if(Ap[i]) res++;
        cout << res << endl;
    }
    return 0;
}
