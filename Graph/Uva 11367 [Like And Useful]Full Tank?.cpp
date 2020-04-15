#include <bits/stdc++.h>
#define N 1005
#define INF 0x3f3f3f3f
using namespace std;

struct node{
    int to, c;
    int rem_c, money;
    bool operator<(const node& n2) const{
        return money > n2.money;
    }
};

int dp[N][105];
bool vis[N][105];
vector<node> g[N];
int p[N];

int main()
{
    int n, m, q;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        g[i].clear();
    }
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    cin >> q;
    while(q--){
        int c, s, e;
        cin >> c >> s >> e;

        memset(vis, 0, sizeof vis);
        memset(dp, INF, sizeof dp);

        priority_queue<node> pq;
        pq.push({s, 0, 0, 0});
        dp[s][0] = 0;
        bool flag = 1;

        while(!pq.empty()){
            node tmp = pq.top(); pq.pop();
            int u = tmp.to, gas = tmp.rem_c;

            if(vis[u][gas]) continue;
            vis[u][gas] = 1;
            if(u == e){
                cout << dp[u][gas] << endl;
                flag = 0;
                break;
            }

            for(int i = 0; i < g[u].size(); ++i){
                int v = g[u][i].to, route = g[u][i].c;
                if(route > gas) continue;
                if(dp[v][gas-route] > dp[u][gas]){
                    dp[v][gas-route] = dp[u][gas];
                    pq.push({v, 0, gas-route, dp[v][gas-route]});
                }
            }

            if(gas < c && dp[u][gas+1] > dp[u][gas] + p[u]){
                dp[u][gas+1] = dp[u][gas] + p[u];
                pq.push({u, 0, gas+1, dp[u][gas+1]});
            }
        }
        if(flag)
            puts("impossible");

    }
    return 0;
}
