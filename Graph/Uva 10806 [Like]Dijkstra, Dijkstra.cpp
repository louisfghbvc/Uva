//find 2 shortest path, and sum it, each edge use only once, very tricky, like flow
#include <bits/stdc++.h>
#define N 105
using namespace std;
int adj[N][N];
int d[N], path[N];
bool inq[N];
int n, m, s, t;
void spfa(){
    queue<int> q;
    memset(inq, 0, sizeof inq);
    for(int i = 1; i <= n; ++i){
        d[i] = 1e9;
        path[i] = s;
    }

    d[s] = 0;
    inq[s] = true;
    q.push(s);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        inq[cur] = false;
        for(int i = 1; i <= n; ++i){
            if(d[i] > d[cur] + adj[cur][i]){
                path[i] = cur;
                d[i] = d[cur] + adj[cur][i];
                if(!inq[i]){
                    inq[i] = true;
                    q.push(i);
                }
            }
        }
    }
}
void change(int to){
    int u = path[to];
    adj[to][u] = -adj[u][to];
    adj[u][to] = 1e9;
    if(u == s) return;
    change(u);
}
int main()
{
    while(cin >> n, n){
        memset(adj, 0x3f, sizeof adj);
        cin >> m;
        for(int i = 0; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = c;
            adj[b][a] = c;
        }

        s = 1; t = n;
        spfa();
        int sum = d[t];
        if(d[t] == 1e9){
            cout << "Back to jail\n";
            continue;
        }
        change(t);

        spfa();

        if(d[t] == 1e9){
            cout << "Back to jail\n";
            continue;
        }

        cout << sum + d[t] << endl;
    }
    return 0;
}
