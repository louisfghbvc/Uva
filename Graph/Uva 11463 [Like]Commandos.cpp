//floyd warshall, very tricky, find minimum dis and pass all node
#include <bits/stdc++.h>
#define N 105
using namespace std;
int d[N][N];
int main()
{
    int t, n, r, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> r;
        vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e7));
        for(int i = 0; i < n; ++i)
            dis[i][i] = 0;
        int s, d;
        for(int i = 0; i < r; ++i){
            cin >> s >> d;
            dis[s][d] = dis[d][s] = 1;
        }

        cin >> s >> d;
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        int mx = 0;
        for(int k = 0; k < n; ++k){
            mx = max(mx, dis[s][k] + dis[k][d]);
        }
        printf("Case %d: %d\n", cas++, mx);
    }
    return 0;
}
