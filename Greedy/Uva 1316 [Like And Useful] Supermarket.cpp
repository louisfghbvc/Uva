// Solution1, suit t is small, n is big
// O(nlogn), sort t decsending and priority_queue value greater.
// each time when ti >= time means can allcocate this sells.
// each time take one max val.
// Next time I will solve this type problem. QQ

#include <bits/stdc++.h>
#define N 10005
using namespace std;
struct node{
    int p, t;
    bool operator<(const node &n2) const{
        return p < n2.p;
    }
}arr[N];
bool cmp(const node n1, const node n2){
    return n1.t > n2.t;
}
int main()
{
    int n;
    while(cin >> n){
        int te = 0;
        for(int i =0; i < n; ++i){
            cin >> arr[i].p >> arr[i].t;
            te = max(arr[i].t, te);
        }
        sort(arr, arr+n, cmp);
        priority_queue<node> pq;
        int ans = 0;
        for(int i = te, j = 0; i >= 1; --i){
            while(arr[j].t >= i && j != n) pq.push(arr[j++]);
            if(!pq.empty()){
                ans += pq.top().p;
                pq.pop();
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// Solution2, each time, list job. and when bigger then queue size means can allocate this job.
// and if now job > queue smallest job. u regret
// swap, and record
#include <bits/stdc++.h>
#define N 10005
using namespace std;
struct node{
    int p, t;
    bool operator<(const node &n2) const{
        return p > n2.p;
    }
}arr[N];
bool cmp(const node n1, const node n2){
    return n1.t < n2.t;
}
int main()
{
    int n;
    while(cin >> n){
        for(int i =0; i < n; ++i){
            cin >> arr[i].p >> arr[i].t;
        }
        sort(arr, arr+n, cmp);
        priority_queue<node> pq;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i].t > pq.size()){ // make queue as much as possible
                ans += arr[i].p;
                pq.push(arr[i]);
            }
            else if(arr[i].p > pq.top().p){ // regret 
                ans -= pq.top().p;
                pq.pop();
                ans += arr[i].p;
                pq.push(arr[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// Solution3, value descending. and use disjoint set, put as deadline as possible
// change parent to prev time just like check remain container. trick and impressive. good problem.
#include <bits/stdc++.h>
#define N 10005
using namespace std;
struct node{
    int p, t;
    bool operator<(const node &n2) const{
        return p > n2.p;
    }
}arr[N];

int nxt[N];
int findp(int x){
    return nxt[x] == -1 ? x : nxt[x] = findp(nxt[x]);
}

int main()
{
    int n;
    while(cin >> n){
        for(int i =0; i < n; ++i){
            cin >> arr[i].p >> arr[i].t;
        }
        sort(arr, arr+n);
        int ans = 0;
        memset(nxt, -1, sizeof nxt);
        for(int i = 0; i < n; ++i){
            int t = findp(arr[i].t);
            if(t){
                ans += arr[i].p;
                nxt[t] = t-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
