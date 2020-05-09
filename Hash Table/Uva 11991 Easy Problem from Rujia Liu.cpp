// Like Graph strcture.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k, v, x;
    while(scanf("%d %d", &n, &m) != -1){
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            mp[x].push_back(i+1);
        }
        while(m--){
            scanf("%d %d", &k, &v);
            if(mp[v].size() < k) puts("0");
            else printf("%d\n", mp[v][k-1]);
        }
    }
    return 0;
}
/**
8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2
**/
