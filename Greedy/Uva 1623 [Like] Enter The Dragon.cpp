// Very Hard to think use this. Greedy. use lower_bound. find next no rain day.
// pre means lake i, prev rain day. 
// ans means no rain day drink which lake.
// key point is use data strcture. can also use disjoint set 

#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int arr[N];
int ans[N], pre[N];

int main()
{
    //freopen("out.txt", "w", stdout);
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(ans, 0, sizeof ans);
        memset(pre, 0, sizeof pre);
        for(int i = 1; i <= m; ++i){
            cin >> arr[i];
        }
        set<int> norain;
        bool ok = 1;
        for(int i = 1; i <= m; ++i){
            if(!arr[i]){
                norain.insert(i);
            }
            else{
                int t = arr[i];
                auto p = norain.lower_bound(pre[t]); // find next day greater than pre
                if(p == norain.end()){
                    ok = 0; break;
                }
                pre[t] = i;
                ans[*p] = t;
                norain.erase(p);
            }
        }
        if(!ok) puts("NO");
        else{
            puts("YES");
            bool f = 1;
            for(int i = 1; i <= m; ++i){
                if(!arr[i]){
                    if(!f) cout << " ";
                    cout << ans[i];
                    f = 0;
                }
            }
            puts("");
        }
    }
    return 0;
}
/**
4
2 4
0 0 1 1
2 4
0 1 0 2
2 3
0 1 2
2 4
0 0 0 1
**/
