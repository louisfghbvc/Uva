// This is Hard on build graph...
// O(VE^2)

#include <bits/stdc++.h>
#define M 55
using namespace std;

int cap[M][M], flow[M][M];
int a[M], pre[M];
int t, n, m, k, x, T = 0, cas = 1;

int EK(int s, int t){
    int res = 0;
    while(1){
        memset(pre, 0, sizeof pre);
        memset(a, 0, sizeof a);
        a[s] = 1e9;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(a[t]) break;
            for(int v = 0; v <= n+m; ++v){
                if(!a[v] && cap[u][v] > flow[u][v]){
                    q.push(v);
                    a[v] = min(a[u], cap[u][v]-flow[u][v]);
                    pre[v] = u;
                }
            }
        }
        if(!a[t]) break;
        for(int cur = t; cur != s; cur = pre[cur]){
            flow[pre[cur]][cur] += a[t];
            flow[cur][pre[cur]] -= a[t];
        }
        res += a[t];
    }

    return res;
}

int main()
{
    cin >> t;
    while(t--){
        memset(cap, 0, sizeof cap);
        memset(flow, 0, sizeof flow);
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            cin >> k;
            for(int j = 0; j < k; ++j){
                cin >> x;
                cap[i][x+n]++;
            }
        }

        for(int i = 2; i <= n; ++i){
            for(int j = n+1; j <= n+m; ++j){
                if(cap[i][j]) cap[i][j]--;
                else cap[j][i] = 1;
            }
        }

        for(int j = n+1; j <= n+m; ++j)
            cap[j][T] = 1;

        printf("Case #%d: %d\n", cas++, EK(1, T));

    }
}
/**
2
2 5
6 1 1 1 1 1 1
3 1 2 2
3 5
4 1 2 1 1
3 2 2 2
5 1 3 4 4 3
**/
