// Observe. maximum spanning tree.

#include <bits/stdc++.h>
#define N 20000
using namespace std;

struct edge{
	int a, b, c;
	bool operator<(edge e2) const {
		return c > e2.c;
	}
}e[N];

int p[N];
int findp(int x){
	if(x == p[x]) return x;
	return p[x] = findp(p[x]); 
}

int main(){
    int n, r, cas = 1;
    while(cin >> n >> r, n+r){
    	memset(e, 0, sizeof e);
    	map<string, int> mp;
    	for(int i = 0; i < r; ++i){
    		string a, b; int c;
    		cin >> a >> b >> c;
    		if(!mp.count(a)) mp[a]=mp.size();
    		if(!mp.count(b)) mp[b]=mp.size();
    		e[i] = {mp[a], mp[b], c};
    	}
    	sort(e, e+r);
    	string a, b;
    	cin >> a >> b;
    	int s = mp[a], t = mp[b], res = INT_MAX;
    	for(int i = 0; i < 205; ++i) p[i] = i;
    	for(int i = 0; i < r; ++i){
    		if(findp(s) == findp(t)) break;
    		int st = findp(e[i].a), ed = findp(e[i].b);
    		if(st == ed) continue;
    		p[ed] = st;
    		res = e[i].c;
    	}
    	printf("Scenario #%d\n", cas++);
    	printf("%d tons\n\n", res);
    }
    return 0;
}
