/**                                          
 __         ______     __  __     __     ______     ______   ______     __  __     ______     __   __   ______    
/\ \       /\  __ \   /\ \/\ \   /\ \   /\  ___\   /\  ___\ /\  ___\   /\ \_\ \   /\  == \   /\ \ / /  /\  ___\   
\ \ \____  \ \ \/\ \  \ \ \_\ \  \ \ \  \ \___  \  \ \  __\ \ \ \__ \  \ \  __ \  \ \  __<   \ \ \'/   \ \ \____  
 \ \_____\  \ \_____\  \ \_____\  \ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  \ \_____\  \ \__|    \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_/   \/_____/   \/_/     \/_____/   \/_/\/_/   \/_____/   \/_/      \/_____/                                       
**/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(All(x)); x.erase(unique(All(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 3e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
**/

LL block[N];
int L[N], R[N]; // block bound, [l, r]
int arr[N];
int belong[N]; // which block id
int block_sz;
LL n, m, u;

void build(){
    int num = (n + block_sz-1) / block_sz;
    for(int i = 1; i <= num; ++i) 
        L[i] = block_sz*(i-1)+1, R[i] = block_sz*i;
    R[num] = n;
    for(int i = 1; i <= num; ++i){
        for(int j = L[i]; j <= R[i]; ++j)
            belong[j] = i;
        sort(block+L[i], block+R[i]+1);
    }
}

int query(int r, int v){
    if(r <= 0) return 0;
    int key = belong[r];
    int res = 0;
    for(int i = 1; i < key; ++i)
        res += lower_bound(block+L[i], block+R[i]+1, v) - block - L[i];
    for(int i = L[key]; i <= r; ++i)
        res += arr[i] < v;
    return res;
}

void update(int p, int v){
    int key = belong[p];
    int pos = lower_bound(block+L[key], block+R[key]+1, arr[p]) - block;
    block[pos] = v;

    // resort block
    if(v < arr[p]){
        while(pos > L[key] && block[pos] < block[pos-1]) 
            swap(block[pos], block[pos-1]), pos--;
    }
    else{
        while(pos < R[key] && block[pos] > block[pos+1]) 
            swap(block[pos], block[pos+1]), pos++;
    }

    arr[p] = v;
}

void solve(int T){
    
    cin >> n >> m >> u;
    block_sz = sqrt(n);

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        block[i] = arr[i];
    }

    build();

    for(int i = 0; i < m; ++i){
        int l, r, v, p;
        cin >> l >> r >> v >> p;
        int k = query(r, v) - query(l-1, v);
        update(p, u * k / (r-l+1));
    }

    for(int i = 1; i <= n; ++i)
        cout << arr[i] << "\n";
}
 
int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
