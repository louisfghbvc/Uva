// A simple disjoint problem, make sure they are not friend, if is friend not union.
// or u will wrong.

#include <bits/stdc++.h>
#define N 100005
using namespace std;

int p[N];
int findp(int x){
    return p[x] < 0 ? x : p[x] = findp(p[x]);
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int t, q;
    string a, b;
    cin >> t;
    while(t--){
        memset(p, -1, sizeof p);
        cin >> q;
        map<string, int> mp;
        while(q--){
            cin >> a >> b;
            if(!mp.count(a)) mp[a] = mp.size();
            if(!mp.count(b)) mp[b] = mp.size();
            int ap = findp(mp[a]), bp = findp(mp[b]);
            if(ap != bp){
                p[ap] += p[bp];
                p[bp] = ap;
            }
            cout << abs(p[ap]) << endl;
        }
    }
    return 0;
}
/**
1
3
Fred Barney
Barney Betty
Betty Wilma
**/
