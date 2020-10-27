// use indegree to check.
// union-find. careful root>1.
// root's num = 0 is fine, cuz must have cycle.
// root's num = 0 is tree.

#include <bits/stdc++.h>
using namespace std;

int p[100005];
int find(int x){
	return p[x] < 0 ? x : p[x] = find(p[x]);
}

int main(){
    int cas = 1;
    vector<int> ind(100005);
    unordered_set<int> tr;
    int a, b;
    memset(p, -1, sizeof p);
    bool tree = 1;
    while(cin >> a >> b && a != -1 && b != -1){
    	if(a+b == 0){
    		int root = 0;
    		for(int x: tr){
    			if(!ind[x]) root++;
    		}
    		if(root > 1) tree = 0;
    		if(tree)
    			printf("Case %d is a tree.\n", cas++);
    		else
    			printf("Case %d is not a tree.\n", cas++);
    		ind = vector<int>(100005);
    		memset(p, -1, sizeof p);
    		tr.clear();
    		tree = 1;
    		continue;
    	}
    	tr.insert(a);
    	tr.insert(b);
    	ind[b]++;
    	a = find(a), b = find(b);
    	if(a != b) p[b] = a;
    	else tree = 0;
    }
    return 0;
}
