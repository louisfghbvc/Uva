//max flow, very simple problem, but useful and impressive
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N 110
int f[N][N], c[N][N], a[N], p[N];
int n, m, s, t, flow;

void EK()
{
    flow = 0;
    queue <int> q;
    while(1){
        memset(a, 0, sizeof a);
        a[s] = INF;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v = 1; v <= n; v++){
                if(!a[v] && c[u][v] > f[u][v]){
                    p[v] = u;
                    q.push(v);
                    a[v] = min(a[u], c[u][v] - f[u][v]);
                }
            }
        }

        if(!a[t]) break;
        for(int u = t; u != s; u = p[u])
        {
            f[p[u]][u] += a[t];
            f[u][p[u]] -= a[t];
        }
        flow += a[t];
    }
}
int main()
{
    int cas = 1;
    while(scanf("%d", &n) != EOF && n){
        scanf("%d%d%d", &s, &t, &m);
        memset(p, 0, sizeof p);
        memset(f, 0, sizeof f);
        memset(c, 0, sizeof c);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            c[u][v] += w; //多重邊
            c[v][u] = c[u][v];
        }
        EK();
        printf("Network %d\n", cas++);
        printf("The bandwidth is %d.\n\n", flow);
    }
    return 0;
}
