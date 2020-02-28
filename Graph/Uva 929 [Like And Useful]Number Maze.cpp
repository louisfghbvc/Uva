#include <bits/stdc++.h>
#define N 1005
using namespace std;
int arr[N][N];
int dp[N][N];
bool vis[N][N];
struct node{
    int x, y, w;
    bool operator<(const node n2) const{
        return w > n2.w;
    }
};
int main()
{
    const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int t, m, n;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(vis, 0, sizeof vis);
        priority_queue<node> pq;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> arr[i][j];
                dp[i][j] = 1e7;
            }
        }
        dp[0][0] = arr[0][0];
        pq.push(node{0, 0, arr[0][0]});
        while(!pq.empty()){
            node cur = pq.top(); pq.pop();
            vis[cur.x][cur.y] = 1;
            for(int k = 0; k < 4; ++k){
                int x = cur.x + dir[k][0], y = cur.y + dir[k][1];
                if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) continue;
                if(cur.w + arr[x][y] < dp[x][y]){
                    dp[x][y] = cur.w + arr[x][y];
                    pq.push(node{x, y, cur.w + arr[x][y]});
                }
            }
        }
        cout << dp[n - 1][m - 1] << endl;
    }
    return 0;
}
