// Math + DP, 組合 and 錯位排序
// 先算C幾取幾，全部建表。
// 接著錯位排序: dp[i] = (i-1)(dp[i-1]+dp[i-2])
// i 放最後一位或不放最後一位
// C m取k 不錯位，開始枚舉錯位，錯位Cn-m取(0~n-m)
// sum of this all case

#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long LL;

LL mod = 1e9+7;
LL C[N][N], dp[N];

void init(){
    for(int i = 0; i < N; ++i){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j){
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    dp[0] = 1, dp[1] = 0;
    for(int i = 2; i < N; ++i)
        dp[i] = ((i-1)*(dp[i-1]+dp[i-2])%mod)%mod;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int t, cas = 1, n, m, k;
    init();
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        LL ans = 0;
        for(int i = 0; i <= n-m; ++i){
            ans += C[n-m][i]*dp[n-k-i];
            ans %= mod;
        }
        ans = (ans*C[m][k])%mod;
        printf("Case %d: %lld\n", cas++, ans);
    }
}
/**
1
5 3 2

**/
