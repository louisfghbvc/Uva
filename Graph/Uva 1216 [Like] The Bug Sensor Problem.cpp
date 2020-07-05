// MST variant, problem is very long.
// if not used each edge make sensor, and (total - sensor number) <= r, then output that distance.
// trick.

#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long LL;
typedef pair<LL, LL> ii;

struct edge{
    LL a, b;
    LL c;
    bool operator<(const edge &e2) const{
        return c < e2.c;
    }
};

LL dis(ii &a, ii &b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int p[N];
int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

int main()
{
    //freopen("out.txt", "w", stdout);
    LL t, r, a, b;
    cin >> t;
    while(t--){
        memset(p, -1, sizeof p);
        cin >> r;
        vector<ii> tmp;
        vector<edge> e;
        while(cin >> a, a != -1){
            cin >> b;
            tmp.push_back({a, b});
        }
        for(int i = 0; i < tmp.size(); ++i){
            for(int j = i+1; j < tmp.size(); ++j){
                e.push_back({i, j, dis(tmp[i], tmp[j])});
            }
        }
        sort(e.begin(), e.end());
        int cnt = tmp.size();
        for(auto &ee: e){
            a = find(ee.a), b= find(ee.b);
            if(a != b){
                p[b] = a;
                cnt--;
            }
            if(cnt <= r){
                printf("%0.lf\n", ceil(sqrt(ee.c)));
                break;
            }
        }
    }
}
/**
1
1
1 1
99999 99999
-1
**/
