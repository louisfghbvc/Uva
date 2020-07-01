// Very Trick, the segment problem can always use priority_queue. 
// the early deadline must work first.
// and binary search the ans, every second can work how many things.
// and the magic is work can split, more funny.
// every second can remain but pq must all down and every thind down.
// O(TlogNlogK)

#include <bits/stdc++.h>
#define N 10005
using namespace std;

struct node{
    int l, r, w;
    bool operator<(node n2) const{
        return r > n2.r;
    }
}arr[N];

bool cmp(node n1, node n2){
    return n1.l < n2.l;
}

int t, n;

bool check(int s){
    priority_queue<node> pq;
    int cnt = 0;
    for(int i = 1; i <= 20000; ++i){
        while(cnt < n && arr[cnt].l == i) pq.push(arr[cnt++]);
        int res = s;
        while(pq.size() && res > 0){
            node cur = pq.top(); pq.pop();
            if(cur.r <= i) return false;
            if(res >= cur.w){
                res -= cur.w;
            }
            else{
                cur.w -= res;
                res = 0;
                pq.push(cur);
            }
        }
    }
    if(cnt == n && pq.empty()) return true;
    return false;
}

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> arr[i].l >> arr[i].r >> arr[i].w;
        sort(arr, arr+n, cmp);
        int l = 0, r = 1e9, ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
/**
3
5
1 4 2
3 6 3
4 5 2
4 7 2
5 8 1
6
1 7 25
4 8 10
7 10 5
8 11 5
10 13 10
11 13 5
8
15 18 10
20 24 16
8 15 33
11 14 14
1 6 16
16 19 12
3 5 12
22 25 10

**/
