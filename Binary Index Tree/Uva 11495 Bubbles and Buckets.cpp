// Just calculate inverse pair. O(NlogN).

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int bit[N];

void add(int x, int v){
    for(++x; x < N; x+=x&-x)
        bit[x] += v;
}

int query(int x){
    int res = 0;
    for(++x; x; x-=x&-x)
        res += bit[x];
    return res;
}

int main() {
    //cin.tie(0); ios::sync_with_stdio(false);
    int n;
    while(cin >> n, n){
        memset(bit, 0, sizeof bit);
        int cnt = 0;
        for(int i = 0, x; i < n; ++i){
            cin >> x;
            cnt += i - query(x);
            add(x, 1);
        }

        if(cnt % 2) cout << "Marcelo\n";
        else cout << "Carlos\n";
    }
}
/**
5 1 5 3 4 2
5 5 1 3 4 2
5 1 2 3 4 5
6 3 5 2 1 4 6
5 5 4 3 2 1
6 6 5 4 3 2 1
0
**/

// Merge sort.
