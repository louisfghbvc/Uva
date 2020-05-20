// top-down and mod rule, check neg and long long.
// memorize.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL arr[205];
LL n, q, d, m;
LL memo[205][25][205];
LL dfs(int c, LL sum, int id){
    if(c == m){
        if(sum) return 0;
        return 1;
    }
    if(id >= n) return 0;
    if(memo[c][sum][id] != -1) return memo[c][sum][id];
    LL res = 0;
    for(int i = id; i < n; ++i){
        res += dfs(c+1, ((sum+arr[i])%d + d)%d, i+1);    
    }
    return memo[c][sum][id] = res;
}

int main()
{
    
    int cas = 1;
    while(cin >> n >> q, n+q){
        for(int i = 0; i < n; ++i) cin >> arr[i];
        printf("SET %d:\n", cas++);
        int qc = 1;
        while(q--){
            memset(memo, -1, sizeof memo);
            cin >> d >> m;
            printf("QUERY %d: %lld\n", qc++, dfs(0, 0, 0));
        }
    }
}
