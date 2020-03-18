//remember u mp.size()-1 may not correct, because the compiler. For safety, use var instead of use mp.size()
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<int> g[28];
int p[28];
int dis[28];

int main() {
    int t, m, q;
    cin >> t;
    while(t--){
        cin >> m >> q;
        
        unordered_map<string, int> mp;
        unordered_map<int, string> i2s;
        for(int i = 0; i < 28; ++i){
            g[i].clear();
        }
        
        for(int i = 0; i < m; ++i){
            string a, b;
            cin >> a >> b;
            if(!mp.count(a)){
                mp[a] = mp.size();
                i2s[mp[a]] = a;
            }
            if(!mp.count(b)){
               mp[b] = mp.size(); 
               i2s[mp[b]] = b;
            }
            g[mp[a]].push_back(mp[b]);
            g[mp[b]].push_back(mp[a]);
        }
        
        for(int i = 0; i < q; ++i){
            string a, b;
            cin >> a >> b;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; 
            for(int j = 0; j < 28; ++j){
                dis[j] = INF;
                p[j] = -1;
            }
            pq.push({0, mp[a]});
            
            while(!pq.empty()){
                pair<int, int> t = pq.top(); pq.pop();
                int u = t.second;
                
                if(dis[u] != INF) continue;
                dis[u] = t.first;
                
                for(auto v : g[u]){
                    if(dis[v] == INF){
                        //cout << i2s[v] << endl;
                        p[v] = u;
                        pq.push({dis[u] + 1, v});
                    }
                }
            }    
            
            string ans = "";
            for(int u = mp[b]; u != -1; u = p[u]) ans += i2s[u][0];
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
        if(t) cout << endl;
    }
    return 0;
}
