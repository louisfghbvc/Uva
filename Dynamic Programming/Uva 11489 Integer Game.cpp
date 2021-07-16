// Just dummy dp. O(tot*S).

#include <bits/stdc++.h>
using namespace std;

int dp[10005][2];
bool dfs(vector<int> &cnt, int tot, bool S){
    if(dp[tot][S] != -1) return dp[tot][S];
    if(S){
        bool res = false;
        for(int i = 0; i <= 9; ++i){
            if(cnt[i] && tot >= i && (tot - i) % 3 == 0){
                cnt[i]--;
                res |= dfs(cnt, tot-i, 0);
                cnt[i]++;
            }
        }
        return dp[tot][S] = res;
    }
    else{
        bool res = true;
        for(int i = 0; i <= 9; ++i){
            if(cnt[i] && tot >= i && (tot - i) % 3 == 0){
                cnt[i]--;
                res = res & dfs(cnt, tot-i, 1);
                cnt[i]++;
            }
        }
        return dp[tot][S] = res;
    }
}

int main() {
    //cin.tie(0); ios::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    for(int t = 0; t < T; ++t){
        memset(dp, -1, sizeof dp);
        printf("Case %d: ", t+1);

        cin >> s;
        vector<int> fre(10);
        int tot = 0;
        for(int i = 0; i < s.size(); ++i){
            fre[s[i] - '0']++;
            tot += (s[i] - '0');
        }

        if(dfs(fre, tot, 1)){
            cout << "S\n";
        }
        else cout << "T\n";
    }
}
/**

**/
