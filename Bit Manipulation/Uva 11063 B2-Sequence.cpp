#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, cas = 1, t;
    while(cin >> n){
    	bool ok = 1;
    	for(int i = 0; i < n; ++i){
    		cin >> t;
    		if(__builtin_popcount(t) > 1) ok = 0;
    	}
    	printf("Case #%d: ", cas++);
    	puts(ok ? "It is a B2-Sequence.\n": "It is not a B2-Sequence.\n");
    }
    return 0;
}
