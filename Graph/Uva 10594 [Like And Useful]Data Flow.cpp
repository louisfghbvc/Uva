//110ms, Min Cost Max Flow, Ek algorithm
#include <bits/stdc++.h>
#define N 105
#define M 5050
typedef long long LL;
LL INF = 1e14;
using namespace std;
LL cost[N][N], dis[N], path[N];
LL f[N][N], c[N][N];
LL n, m, s, t, data, cap, flow;
LL ans;
bool inq[N];
bool spfa(){
    memset(inq, 0, sizeof inq);
    memset(path, -1, sizeof path);
    for(int i = 1; i <= n; i++)
        dis[i] = INF;
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    dis[s] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = false;

        for(int v = 1; v <= n; ++v){
            if(f[v][u] > 0 && dis[u] + (-cost[v][u]) < dis[v]){
                dis[v] = dis[u] - cost[v][u];
                path[v] = u;
                if(!inq[v]){
                    inq[v] = true;
                    q.push(v);
                }
            }
            else if(c[u][v] > f[u][v] && dis[v] > dis[u] + cost[u][v]){
                dis[v] = dis[u] + cost[u][v];
                path[v] = u;
                if(!inq[v]){
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(dis[t] == INF) return false;

    return true;
}

void MCMF(){
    ans = 0;
    flow = 0;
    while(spfa()){
        LL a = INF;
        for(int u = t; u != s; u = path[u]){
            a = min(a, c[path[u]][u] - f[path[u]][u]);
        }
        for(int u = t; u != s; u = path[u]){
            f[path[u]][u] += a;
            f[u][path[u]] -= a;
        }

        ans += dis[n] * a;

        flow += a;
    }
}

int main()
{
    while(cin >> n >> m){
        memset(cost, 0, sizeof cost);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cost[i][j] = INF;
        memset(f, 0, sizeof f);
        memset(c, 0, sizeof c);

        for(int i = 0; i < m; ++i){
            int a, b, w;
            cin >> a >> b >> w;
            cost[a][b] = w;
            cost[b][a] = w;
            c[a][b] = c[b][a] = 1;
        }

        cin >> data >> cap;

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(c[i][j]){
                    c[i][j] = c[j][i] = cap;
                }
            }
        }
        c[0][1] = c[1][0] = data;
        s = 0; t = n;

        MCMF();

        if(data == flow){
            cout << ans << endl;
        }
        else
            cout << "Impossible.\n";
    }
    return 0;
}
