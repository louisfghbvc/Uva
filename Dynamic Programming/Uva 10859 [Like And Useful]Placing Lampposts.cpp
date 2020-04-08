#include <bits/stdc++.h>
#define N 1005
#define M 2005
using namespace std;

//solve aM + b, a is minimum road, b is one light numbers

vector<int> g[N];
bool vis[N];
int dp[N][2];
int n, m;

void dfs(int u){
    vis[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = M;
    for(auto v : g[u]){
        if(vis[v]) continue;
        dfs(v);
        dp[u][0] += dp[v][1] + 1; // u not put, from child put + 1
        if(dp[v][0] < dp[v][1]){
            dp[u][1] += dp[v][0] + 1;// u put, from child not put + 1
        }
        else{
            dp[u][1] += dp[v][1];
        }
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; ++i) g[i].clear();
        memset(vis, 0, sizeof vis);

        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(i);
                ans += min(dp[i][0], dp[i][1]);
            }
        }

        printf("%d %d %d\n", ans/M, m-ans%M, ans%M);
    }
    return 0;
}
