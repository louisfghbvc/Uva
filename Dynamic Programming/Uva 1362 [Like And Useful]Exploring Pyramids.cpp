//Classic, 多叉樹走訪方式, Hard to think.
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int memo[305][305];
const int mod = 1e9;
string s;

LL dp(int i, int j){
    if(i == j) return 1;
    if(s[i] != s[j]) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    LL res = 0;
    for(int k = i + 2; k <= j; ++k){
        res += dp(i+1, k-1) * dp(k, j);
        res %= mod;
    }
    return memo[i][j] = res;
}

int main()
{
    while(cin >> s){
        memset(memo, -1, sizeof memo);
        cout << dp(0, s.size()-1) << endl;
    }
    return 0;
}
