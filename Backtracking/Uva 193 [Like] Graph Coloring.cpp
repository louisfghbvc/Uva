// Enum node, not Enum path, cool. Learn it.

#include <bits/stdc++.h>
#define N 105
using namespace std;

vector<int> g[N];
vector<int> tmp, ans;
bool isblack[N];
int t, n, k, mx;

void dfs(int i){
    if(i > n){
        if(tmp.size() > mx || (tmp.size() == mx && isblack[n])){
            mx = tmp.size();
            ans = tmp;
        }
        return;
    }

    bool black = 1;
    for(const int &v : g[i]){
        if(isblack[v]) black = 0;
    }
    if(black){
        tmp.push_back(i);
        isblack[i] = 1;
        dfs(i+1);
        isblack[i] = 0;
        tmp.pop_back();
    }
    dfs(i+1);
}


int main()
{
    //freopen("out.txt", "w", stdout);

    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(isblack, 0, sizeof isblack);
        for(int i = 1; i <= n; ++i) g[i].clear();
        tmp.clear(); ans.clear();

        for(int i = 0; i < k; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        mx = 0;
        dfs(1);

        cout << mx << endl;
        bool f = 1;
        for(const auto &x : ans){
            if(!f) cout << " ";
            cout << x;
            f = 0;
        }
        cout << endl;
    }

    return 0;
}
