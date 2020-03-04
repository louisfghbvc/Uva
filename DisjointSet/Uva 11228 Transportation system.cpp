#include <bits/stdc++.h>
#define N 1005
using namespace std;

int p[N];

int findp(int x){
    if(x == p[x])
        return x;
    return p[x] = findp(p[x]);
}

struct edge{
    int a, b;
    double c;
    bool operator<(const edge &e2) const{
        return c < e2.c;
    }
};

double dis(const pair<int, int> &x, const pair<int, int> &y){
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

int main()
{
    int t, n, r, cas = 1;
    cin >> t;
    while(t--){
        
        unordered_map <int, pair<int, int>> mp;
        vector<edge> e;
        int st = 1;
        double road = 0, rroad = 0;
        
        cin >> n >> r;
        
        for(int i = 0; i < n; ++i){
            int x, y;
            cin >> x >> y;
            p[i] = i;
            mp[i] = {x, y};
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                e.push_back({i, j, dis(mp[i], mp[j])});
            }
        }
        
        sort(e.begin(), e.end());
        
        for(int i = 0, c = 0; i < e.size() && c < n - 1; ++i){
            int a = findp(e[i].a), b = findp(e[i].b);
            if(a == b) continue;
            if(e[i].c <= r){
                road += e[i].c;
                p[b] = a;
            }
            else{
                rroad += e[i].c;
                p[b] = a;
                st++;
            }
            c++;
        }
        
        printf("Case #%d: %d %.0f %.0f\n", cas++, st, road, rroad);
    }
   
    return 0;
}
