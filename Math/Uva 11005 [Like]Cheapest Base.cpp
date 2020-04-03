//4-base, mod4, ... etc
//input 10-base, so you need to translate into other base.
//compute the cost according to that base number. 
//decimal number to other-base number. 
#include <bits/stdc++.h>
using namespace std;
int cost[37], ans[37];
int main(){
    int t, cas = 1, q, n;
    cin >> t;
    while(t--){
    	for(int i = 0; i <= 35; ++i)
    			cin >> cost[i];
    	cin >> q;
    	printf("Case %d:\n", cas++);
    	while(q--){
    		int cheap = INT_MAX;
    		cin >> n;
    		for(int i = 2; i <= 36; ++i){
    			int t = n, sum = 0;
    			while(t > 0){
    				sum += cost[t%i];
    				t /= i;
    			}
    			cheap = min(cheap, sum);
    			ans[i] = sum;
    		}
    		
    		printf("Cheapest base(s) for number %d:", n);
    		for(int i = 2; i <= 36; ++i){
    			if(ans[i] == cheap)
    				printf(" %d", i);
    		}
    		puts("");
    	}
    	if(t) puts("");	
    }
    return 0;
}
