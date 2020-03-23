#include <bits/stdc++.h>
#define N 200005
using namespace std;

bool np[N];
vector<int> p;

int cnt(int x){
	int ans = 0;
	while(x > 0){
		ans += x%10;
		x/=10;
	}
	return ans;
}

void init(){
	for(int i = 2; i < N; ++i){
		if(!np[i]){
			p.push_back(i);
			for(int j = i * 2; j < N; j+=i){
				np[j] = true;
			}
		}
	}
}

int main(){
    int t, n;
    init();
    cin >> t;
    while(t--){
    	cin >> n;
    	for(int i = n + 1; ; ++i){
    		if(i < N && !np[i]) continue;
    		int ti = i, sol = 0, judge = cnt(i);
    		for(int k = 0; k < p.size(); ++k){
    			if(p[k] > ti) break;
    			int c = 0;
    			while(ti % p[k] == 0){
    				ti /= p[k];
    				c++;
    			}
    			if(c) sol += c * cnt(p[k]);
    		}
    		if(ti > N && ti != i) sol += cnt(ti);
    		if(sol == judge){
    			cout << i << endl;
    			break;
    		}
    	}
    }
    return 0;
}
