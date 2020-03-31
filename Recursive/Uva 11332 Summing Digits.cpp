#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int func(LL x){
	if(x < 10)
		return x;
	int ans = 0;
	while(x > 0){
		ans += x%10;
		x/=10;
	}
	return func(ans);
}
int main(){
	LL n;
	while(cin >> n, n){
		printf("%d\n", func(n));
	}
    return 0;
}
