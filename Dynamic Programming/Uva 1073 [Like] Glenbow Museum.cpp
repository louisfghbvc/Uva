// Very Hard Dp.
// Hard to think. Not totally understand this solution.

#include <bits/stdc++.h>
#define N 1000
using namespace std;
typedef long long LL;
LL ans[N+1], dp[N+5][5][2];

int main()
{
    for(int k = 0; k < 2; k++){
        dp[1][0][k] = 1;
        for(int i = 2; i <= N; ++i){
            for(int j = 0; j < 5; j++){
                dp[i][j][k] = dp[i-1][j][k];
                if(j) dp[i][j][k] += dp[i-1][j-1][k];
            }
        }
    }
    memset(ans, 0, sizeof ans);
    for(int l = 4; l <= N; ++l){
        if(l & 1) continue;
        int o = (l-4)/2;
        int r = l-o;
        ans[l] = dp[r][3][0] + dp[r][4][0] + dp[r][4][1];
    }
    int x, cas = 1;
    while(cin >> x, x){
        printf("Case %d: %lld\n", cas++, ans[x]);
    }
    return 0;
}
