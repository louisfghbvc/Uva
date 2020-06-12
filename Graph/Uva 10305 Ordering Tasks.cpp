// only bfs can work.
// use indegree to determine the current node.
// O(N)

#include<bits/stdc++.h>
using namespace std;
vector<int> g[105];

int main()
{
    int n, m;
    while(cin >> n >> m, n+m){
        for(int i = 1; i <=n ; ++i) g[i].clear();
        int in[n+2] = {};
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            in[b]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; ++i){
            if(!in[i]) q.push(i);
        }
        bool f = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(f) cout << " ";
            cout << u;
            f = 1;
            for(auto &v: g[u]){
                if(--in[v] == 0) q.push(v);    
            }
        }
        cout << "\n";
    }
}
/**
1->2
2->3
1->3
1->5
**/
