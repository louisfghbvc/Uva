// Observe. just sort. and compare.
// each pair a, b and b, a must appear twice

#include <bits/stdc++.h>
#define N 500050
using namespace std;
long long s[N], t[N];
int main(){
    int n;
    while(cin >> n, n){
    	for(int i= 0; i < n; ++i) cin >> s[i] >> t[i];
    	sort(s, s+n); sort(t, t+n);
    	bool ok = 1;
    	for(int i = 0; i < n; ++i){
    		if(s[i] != t[i]) ok = 0;
    	}
    	puts(ok ? "YES" : "NO");
    }
    return 0;
}
