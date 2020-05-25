// slow solution, Top-down. O(N^2)
#include <bits/stdc++.h>
using namespace std;

int n, k;
int memo[105][105];
const int mod = 1e6;
int dfs(int sum, int c){
    if(sum > n) return 0;
    if(c == k) return sum == n;
    if(memo[sum][c] != -1) return memo[sum][c];
    int res = 0;
    for(int i = 0; i <= n; ++i){
        res += dfs(sum+i, c+1);
        res %= mod;
    }
    return memo[sum][c] = res;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    while(cin >> n >> k, n+k){
        memset(memo, -1, sizeof memo);
        cout << dfs(0, 0) << "\n";
    }
    return 0;
}

// bottom-up O(N^2).
// dp[n][k] = Choose k(dp[n-1][k-1])+ not choose k(dp[n-1][k])
#include <bits/stdc++.h>
using namespace std;

int n, k;
long long C[205][205];
const int mod = 1e6;
int main()
{
    //freopen("out.txt", "w", stdout);
    C[0][0] = 1;
    for(int N = 1; N <= 201 ; ++N){
        C[N][0] = 1;
        for(int K = 1; K <= N; ++K){
            C[N][K] = (C[N-1][K-1] + C[N-1][K]) % mod;
        }
    }
    while(cin >> n >> k, n+k){
        cout << C[n+k-1][k-1] << "\n";
    }
    return 0;
}
