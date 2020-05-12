// Solution1 Subset. O(2^p * p). Enum.
#include <bits/stdc++.h>
using namespace std;

int len[25];
int main()
{
    //freopen("out.txt", "w", stdout);
    int t, n, p;
    cin >> t;
    while(t--){
        cin >> n >> p;
        for(int i = 0; i < p; ++i) cin >> len[i];
        bool ok = 0;
        for(int i = 0; i < (1<<p); ++i){
            int sum = 0;
            for(int j = 0; j < p; ++j){
                if(i & (1<<j)) sum += len[j];
            }
            if(sum == n){
                ok = 1; break;
            }
        }
        puts(ok ? "YES": "NO");
    }
    return 0;
}

// Solution2 dp 01 bag.
/**
4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567
**/
