// Calculate tree diameter. need 3 times. first find farthest. second farest and then update again.
// O(N).

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 5e3+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
7
2 2 3
3 1 6 7
3 1 4 5
1 3
1 3
1 2
1 2

**/

vector<int> g[N];

int dist[N];
int mx, mxp;
void dfs(int u, int dep = 0, int p = -1){
    dist[u] = max(dep, dist[u]);
    if(dep > mx){
        mx = dep;
        mxp = u;
    }
    for(int v: g[u]){
        if(v == p) continue;
        dfs(v, dep+1, u);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n){
        memset(dist, 0, sizeof dist);
        for(int i = 1, k; i <= n; ++i){
            g[i].clear();
            cin >> k;
            for(int j = 0, v; j < k; ++j){
                cin >> v;
                g[i].push_back(v);
            }
        }

        mx = 0, mxp = 1;
        dfs(mxp);
        dfs(mxp);
        dfs(mxp);

        vector<int> best, worst;
        int mn = *min_element(dist + 1, dist + n + 1);
        for(int i = 1; i <= n; ++i){
            if(dist[i] == mn){
                best.push_back(i);
            }
            else if(dist[i] == mx){
                worst.push_back(i);
            }
        }
        cout << "Best Roots  :";
        for(int x: best)
            cout << " " << x;
        cout << "\nWorst Roots :";
        for(int x: worst)
            cout << " " << x;
        cout << "\n";
    }
    return 0;

}

/**
Enjoy the problem.
**/
