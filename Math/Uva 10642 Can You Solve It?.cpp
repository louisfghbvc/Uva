//O(1). Observe. 等差級數和相差+x相差
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, cas = 1;
    cin >> t;
    while(t--){
    	long long x[2], y[2], st, ed;
    	cin >> x[0] >> y[0] >> x[1] >> y[1];
    	st = (1+x[0]+y[0])*(x[0]+y[0])/2;
    	ed = (1+x[1]+y[1])*(x[1]+y[1])/2;
    	printf("Case %d: %lld\n", cas++, ed - st + x[1] - x[0]);
    }
    return 0;
}
/*
0 1
1 2
2 3
3 4
4 5
*/

