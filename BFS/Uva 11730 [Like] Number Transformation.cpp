// Complete serach use bfs. and some cut.
// use cnt as visited, when duplicate num or bigger then t ignore. 
// Come on, u can do it !!!

#include <bits/stdc++.h>
#define N 1005
using namespace std;
vector<int> p;
bool np[N];
void init(){
	for(int i = 2; i < N; ++i){
		if(!np[i]){
			p.push_back(i);
			for(int j = 2*i; j < N; j+=i)
				np[j] = 1;
		}
	}
}
int main(){
    init();
    int cas = 1, s, t;
    while(cin >> s >> t, s+t){
    	printf("Case %d: ", cas++);
    	if(s == t){
    		puts("0"); continue;
    	}
    	queue<int> q;
    	q.push(s);
    	int cnt[N] = {};
    	while(!q.empty()){
    		int cur = q.front(); q.pop();
    		if(cur == t) break;
    		for(int i = 0; i < p.size() && p[i] < cur; ++i){
    			if(cur%p[i] == 0){
    				int nxt = cur+p[i];
    				if(nxt > t || cnt[nxt]) continue;
    				q.push(nxt);
    				cnt[nxt] = cnt[cur]+1;
    			}
    		}
    	}
    	printf("%d\n", cnt[t] ? cnt[t] : -1);
    }
    return 0;
}
