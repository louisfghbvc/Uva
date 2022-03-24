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
// template <class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 1e5+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

vi product(vi &a, vi &b, int n) {
    int sz = min(sz(a) + sz(b) + 1, n);
    vi c(sz);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (i+j < sz)
                c[i+j] += a[i]*b[j];
        }
    }
    return c;
}

void solve(int _) {
    int n;
    while (cin >> n) {
        if (n == 0) {
            cout << "1 = 0\n";
            continue;
        }

        vi arr(n);
        cin >> arr;

        vi a(2, 0);
        a[1] = 1, a[0] = -arr[0];
        for (int i = 1; i < n; ++i) {
            vi b(2); b[1] = 1; b[0] = -arr[i];
            a = product(a, b, n+1);
        }

        // i = 0, 0 
        if (n == 1) {
            cout << "x ";
        }
        else {
            cout << "x^" << n << " ";
        }
        for (int i = n-1; i >= 0; --i) {
            if (i == 0) {
                if (a[i] >= 0)
                    cout << "+ " << abs(a[i]) << ' ';
                else
                    cout << "- " << abs(a[i]) << ' ';
            }
            else {
                if (a[i] == 0) continue;
                else if(a[i] > 0)
                    cout << "+ " << (abs(a[i]) == 1 ? "" : to_string(abs(a[i])));
                else
                    cout << "- " << (abs(a[i]) == 1 ? "" : to_string(abs(a[i])));
                if (i == 1)
                    cout << "x";
                else
                    cout << "x^" << i;
                cout << " ";
            }
        }

        cout << "= 0\n";
    }
}       

int main(){
    // Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
