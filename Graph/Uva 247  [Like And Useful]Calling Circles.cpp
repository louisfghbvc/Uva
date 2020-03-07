//tarjan is awesome. SCC
#include <bits/stdc++.h>
#define N 30
using namespace std;
int n, m, cas = 0, cur;
vector<int> g[N];
string name[N];
int dfn[N], low[N];
bool inst[N];
stack<int> st;

void dfs(int u){
    dfn[u] = low[u] = ++cur;
    st.push(u);
    inst[u] = true;

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inst[v]){//same cycle
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(dfn[u] == low[u]){
        int nxt;
        bool f = true;
        do{
            nxt = st.top(); st.pop();
            inst[nxt] = false;
            if(!f)
                cout << ", ";
            cout << name[nxt];
            f = 0;
        }while(nxt != u);
        cout << endl;
    }
}

int main()
{
    while(cin >> n >> m, n + m){

        unordered_map<string, int> mp;
        for(int i = 0; i < n; ++i)
            g[i].clear();
        for(int i = 0; i < m; ++i){
            string s1, s2;
            cin >> s1 >> s2;
            if(!mp.count(s1))
                mp[s1] = mp.size(), name[mp[s1]] = s1;
            if(!mp.count(s2))
                mp[s2] = mp.size(), name[mp[s2]] = s2;
            g[mp[s1]].push_back(mp[s2]);
        }

        cur = 0;
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(inst, 0, sizeof inst);

        if(cas)
            cout << "\n";
        printf("Calling circles for data set %d:\n", ++cas);
        for(int i = 0; i < n; ++i){
            if(!dfn[i]){
                dfs(i);
            }
        }

    }
    return 0;
}
