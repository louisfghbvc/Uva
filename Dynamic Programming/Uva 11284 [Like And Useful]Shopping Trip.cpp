// Super hard problem....
// first all pair shortest path
// and dp[1<<i][i] = -g[0][u] + profit[u]. this is base, mean u go to origin
// and init all case to -inf
// then state 1 ~ 1<<store.size()
// each state can go to 0. is dp[state][j] - g[store[j]][0]
// and each state enum all next k. dp[state|(1<<k)][k] =  max{dp[state][j]-g[store[j]][store[k]] + profit[store[k]]}
// put each state into vector. sort from one's bit smallest.

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int g[55][55];
int main(){
    int t, n, m, p;
    cin >> t;
    while(t--){
    	memset(g, 0x3f, sizeof g);
    	cin >> n >> m;
    	for(int i = 0; i<m; ++i){
    		int u, v, a, b;
    		scanf("%d %d %d.%d", &u, &v, &a, &b);
    		g[u][v] = g[v][u] = min(g[u][v], a*100+b);
    	}
    	cin >> p;
    	vector<int> store;
    	int profit[55] = {};
    	for(int i = 0; i < p; ++i){
    		int u, a, b;
    		scanf("%d %d.%d", &u, &a, &b);
    		profit[u] += a*100+b;
    	}
    	
    	for(int i = 0; i <= n; ++i)
    		if(profit[i] > 0) store.push_back(i);
    	
    	for(int i= 0; i <= n; ++i) g[i][i] = 0;
    	for(int k = 0; k <= n; ++k)
    		for(int i = 0; i <= n; ++i)
    			for(int j= 0; j <=n ;++j)
    				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
    	
    	int res = -inf;
    	int dp[1<<12][12];
    	vector<pair<int, int>> o;
    	for(int i= 0; i< (1<<store.size()); ++i){
    		for(int j = 0; j < store.size(); ++j)
    			dp[i][j] = -inf;
    		o.push_back({__builtin_popcount(i), i});
    	}
    	
    	for(int i= 0; i < store.size(); ++i){
    		int u = store[i];
    		dp[1<<i][i] = -g[0][u] + profit[u]; 
    	}
    	
    	sort(o.begin(), o.end());
    	for(int i = 0; i < o.size(); ++i){
    		int state = o[i].second;
    		for(int j = 0; j < store.size(); ++j){
    			if(dp[state][j] == -inf) continue;
    			
    			int u = store[j];
    			res = max(res, -g[u][0] + dp[state][j]);
    			for(int k= 0; k < store.size(); ++k){
    				if(state&(1<<k)) continue;
    				int v = store[k];
    				dp[state|(1<<k)][k] = max(dp[state|(1<<k)][k], dp[state][j] - g[u][v] + profit[v]);
    			}
    		}
    	}
    	if(res > 0) printf("Daniel can save $%d.%02d\n", res/100, res%100);
    	else puts("Don't leave the house");
    }
    return 0;
}
