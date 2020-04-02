#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, a, b, cas = 1;
    cin >> t;
    while(t--){
    	cin >> a >> b;
    	int sum = 0;
    	if(a % 2 == 0) a++;
    	if(b % 2 == 0) b--;
    	for(int i = a; i <= b; i+=2) sum+=i;
    	printf("Case %d: %d\n", cas++, sum);
    }
    return 0;
}
