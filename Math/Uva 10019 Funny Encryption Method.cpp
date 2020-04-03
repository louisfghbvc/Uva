#include <bits/stdc++.h>
using namespace std;

int cnt(int x){
	int res = 0;
	while(x > 0){
		int t = x%10;
		res += __builtin_popcount(t);
		x /= 10;
	}
	return res;
}

int main(){
    int t, m;
    cin >> t;
    while(t--){
    	cin >> m;
    	int b1 = __builtin_popcount(m), b2 = cnt(m);
    	printf("%d %d\n", b1, b2);
    }
    return 0;
}
