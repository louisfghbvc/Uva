#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

string s;
LL dp[250];
LL dfs(int i){
    if(i == s.size()) return 0;
    if(dp[i] != -1) return dp[i];

    LL res = 0, sum = 0;
    // enum split point
    for(int j = i; j < s.size(); ++j){
        sum = sum * 10 + s[j] - '0';
        if(sum > INT_MAX) break;
        res = max(res, sum + dfs(j+1));
    }
    return dp[i] = res;
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << dfs(0) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--)
        solve();
}
