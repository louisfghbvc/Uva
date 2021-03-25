#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 305;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool check(int &mask, int x){
    for(int i = 0; i < 5; ++i){
        if((1<<(x%10)) & mask) return false;
        mask |= (1<<(x%10));
        x /= 10;
    }
    return x == 0;
}

void solve(){
    int t;
    bool f = 0;
    while(cin >> t, t){
        if(f) cout << "\n";
        f=1;
        vector<pair<int, int>> ans;

        for(int i = 1; i < 100000; ++i){
            int mask = 0;
            if(check(mask, i)){
                if(check(mask, i*t)){
                    ans.push_back({i*t, i});
                }
            }
        }

        sort(ans.begin(), ans.end());
        if(ans.empty()){
            printf("There are no solutions for %d.\n", t);
        }
        else{
            for(auto &p: ans){
                printf("%05d / %05d = %d\n", p.first, p.second, t);
            }
        }
    }
}

int main()
{
    //Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
