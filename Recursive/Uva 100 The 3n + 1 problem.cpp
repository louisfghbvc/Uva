#include <bits/stdc++.h>
#define N 2000005
using namespace std;

int memo[N];
int func(int x){
	if(x == 1) return 1;
	if(x & 1) x = 3*x + 1;
	else x = x/2;
	if(x < N && memo[x]) return memo[x];
	int ret = 1 + func(x);
	if(x < N) memo[x] = ret;
	return ret;
}

int main(){
    int a, b;
    memset(memo, 0, sizeof memo);
    while(cin >> a >> b){
    	int mx = 0;
    	for(int i = min(a, b); i <= max(a, b); ++i){
    		mx = max(mx, func(i));
    	}
    	printf("%d %d %d\n", a, b, mx);
    }
    return 0;
}
