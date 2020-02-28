//spfa, negative cycle
#include <bits/stdc++.h>
#define N 1005
#define M 2005
using namespace std;
vector<pair<int, int>> adj[N];
int d[N];
bool spfa(int n){
    bool inq[n + 1] = {};
    int fre[n + 1] = {};
    queue<int> q;
    d[0] = 0;
    q.push(0);
    inq[0] = true;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        inq[cur] = false;
        for(int i = 0; i < adj[cur].size(); ++i){
            int to = adj[cur][i].first, c = adj[cur][i].second;
            if(d[to] > d[cur] + c){
                d[to] = d[cur] + c;
                if(!inq[to]){
                    if(fre[to]++ > n - 1)
                        return true;
                    inq[to] = true;
                    q.push(to);
                }
            }
        }
    }

    return false;
}
int main()
{
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            adj[i].clear();
            d[i] = 1e9;
        }
        for(int i = 0; i < m; ++i){
            int x, y, t;
            cin >> x >> y >> t;
            adj[x].push_back({y, t});
        }
        if(spfa(n))
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
    return 0;
}
