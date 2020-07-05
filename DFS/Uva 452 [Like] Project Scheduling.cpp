// O(N^2). Like topological sort, but the sum are largest. not total... T^T

#include <bits/stdc++.h>
#define N 28
using namespace std;
int in[N], wt[N], sum[N];
int g[N][N];

void dfs(int u){
    int t = 0;
    for(int v = 0; v < 27; ++v) if(g[u][v]){
        dfs(v);
        t = max(sum[v], t);
    }
    sum[u] = t+wt[u];
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    string s;
    while(t--){
        memset(in, 0, sizeof in);
        memset(wt, 0, sizeof wt);
        memset(g, 0, sizeof g);
        memset(sum, 0, sizeof sum);

        while(getline(cin, s)){
            if(s.empty()) break;
            stringstream ss(s);
            char v, u; int w;
            ss >> v >> w;
            wt[v-'A'] = w;
            while(ss >> u){
                g[u-'A'][v-'A'] = 1;
                in[v-'A']++;
            }
        }

        int mx = 0;
        for(int i = 0; i < 27; ++i) if(!in[i]){
            dfs(i);
            mx = max(sum[i], mx);
        }
        cout << mx << endl;
        if(t) puts("");
    }
}
/**
2

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC

**/
