//minimal segment problem. impressive
#include <bits/stdc++.h>
#define N 100005
using namespace std;
struct point{
	int l, r;
	bool operator<(const point &p2) const{
		return l < p2.l;
	}
}p[N];
int main(){
    int t, m, a, b;
    cin >> t;
    while(t--){
    	cin >> m;
    	int id = 0;
    	while(cin >> a >> b){
    		if(!a && !b) break;
    		p[id++] = {a, b};
    	}
    	sort(p, p + id);
    	int x = 0;
    	vector<point> ans;
    	for(int i = 0; i < id; ++i){
    		int j = -1, mx = 0;
    		for(; i < id && p[i].l <= x; ++i){
    			if(mx < p[i].r){
    				mx = p[i].r;
    				j = i;
    			}
    		}
    		if(j == -1) break;
    		ans.push_back(p[j]);
    		x = mx;
    		if(x >= m) break;
    		i--;
    	}
    	if(x < m){
    		cout << 0 << endl;
    	}
    	else{
	    	cout << ans.size() << endl;
	    	for(int i = 0; i < ans.size(); ++i){
	    		cout << ans[i].l << " " << ans[i].r << endl;
	    	}
    	}
    	if(t) cout << endl;
    }
    return 0;
}
