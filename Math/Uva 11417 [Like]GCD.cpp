//Observe. memorize.
#include <bits/stdc++.h>
#define N 505
using namespace std;
typedef long long LL;
LL memo[N];
LL G(int n){
	if(n == 1) return 0;
	if(memo[n]) return memo[n];
	LL ans = G(n-1);
	for(int i = 1; i < n; ++i){
		ans += __gcd(i, n);
	}
	return memo[n] = ans;
}
int main(){
	int n;
	while(cin >> n, n){
		cout << G(n) << endl;
	}
    return 0;
}
/*
N = 1 ,= 0
N = 2, (1,2) = 1
N = 3, (1,2),(1, 3) (2, 3) =3
*/
