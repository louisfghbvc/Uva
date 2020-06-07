// Sort two array from small.
// and compare when knight can dragon.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int n, m;
    while(cin >> n >> m, n+m){
        int hd[n+1], kt[m+1];
        for(int i = 0; i < n; ++i){
            cin >> hd[i];
        }
        for(int i = 0; i < m; ++i){
            cin >> kt[i];
        }
        sort(hd, hd+n);
        sort(kt, kt+m);
        int cost = 0;
        bool ok = 1;
        for(int i = 0, j = 0; i < n; ++i, ++j){
            while(j < m && kt[j] < hd[i]) j++;
            if(j == m){
                ok = 0; break;
            }
            cost += kt[j];
        }
        if(ok) cout << cost << "\n";
        else puts("Loowater is doomed!");
    }
    return 0;
}
/**
2 3
5
4
7
8
4
2 1
5
5
10
0 0
**/
