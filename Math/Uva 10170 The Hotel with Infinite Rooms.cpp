//can use formula to solve. but I use approximate.
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL s, d;
    while(cin >> s >> d){
    	LL ans = s, l = s, r = 1e9;
    	while(l <= r){
    		LL mid = (l+r)/2;
    		if((s+mid)*(mid-s+1) >= 2LL*d){
    			r = mid - 1;
    			ans = mid;
    		}
    		else
    			l = mid + 1;
    	}
    	cout << ans << endl;
    }
    return 0;
}
/*
(s+ans)*(ans-s+1) >= 2*d
*/
