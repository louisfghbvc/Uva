//Observe. Wall can from n-1 + 2 brick, n-2 +1 brick => f(n) = f(n-1)+f(n-2)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int n;
    while(cin >> n, n){
    	if(n <= 2){
    		cout << n << endl; continue;
    	}
    	LL f0 = 1, f1 = 2, f;
    	for(int i = 3; i <= n; ++i){
    		f = f0+f1;
    		f0 = f1;
    		f1 = f;
    	}
    	cout << f << endl;
    }
    return 0;
}
/*
1 1
2 11 2
3 111 12 21
4 1111 112 121 211 22
*/
