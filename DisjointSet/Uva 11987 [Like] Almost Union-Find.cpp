// Some trick move, move one change map number.

#include <bits/stdc++.h>
#define N 200005
using namespace std;
int p[N];
int mp[N];
int sz[N], sum[N];
int findp(int x){
	if(x == p[x]) return x;
	return p[x] = findp(p[x]);
}

int main(){
    int n, m, c, a, b;
    while(cin >> n >> m){
    	for(int i = 1; i <= n; ++i) p[i] = i, sz[i] = 1, mp[i] = i, sum[i] = i;
    	int nc = n;
    	while(m--){
    		cin >> c;
    		if(c == 3){
    			cin >> a;
    			cout << sz[findp(mp[a])] << " " << sum[findp(mp[a])] << "\n";
    		}
    		else{
    			cin >> a >> b;
    			int ar = findp(mp[a]), br = findp(mp[b]);
    			if(c == 1){
    				if(ar == br) continue;
    				p[ar] = br; 
    				sz[br] += sz[ar];
    				sum[br] += sum[ar];
    				sz[ar] = 0; sum[ar] = 0;
    			}
    			else{
    				if(ar == br) continue;
    				mp[a] = ++n;
    				p[mp[a]] = br;
    				sz[ar]--; sz[br]++;
    				sum[br] += a; sum[ar] -= a;
    			}
    		}
    	}
    }
    return 0;
}
