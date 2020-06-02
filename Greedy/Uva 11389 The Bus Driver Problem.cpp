// Classsic, make total balance.
// balance is minimum.
// Sort.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int n, d, r;
    while(cin >> n >> d >> r, n+d+r){
        int u[n+1], dn[n+1];
        for(int i= 0; i < n; ++i){
            cin >> u[i];
        }
        for(int i= 0; i < n; ++i){
            cin >> dn[i];
        }
        sort(u, u+n);
        sort(dn, dn+n, greater<int>());
        int ans = 0;
        for(int i= 0; i<n; ++i){
            if(u[i]+dn[i] > d)
                ans += (u[i]+dn[i]-d)*r;
        }
        cout << ans << "\n";
    }
    return 0;
}
/**
2 20 5
10 15
10 15
2 20 5
10 10
10 10
0 0 0
**/
