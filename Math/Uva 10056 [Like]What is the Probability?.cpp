//白努利機率問題, 無窮等比級數和
#include <bits/stdc++.h>
using namespace std;
int main(){
    int s, n, id;
    double p;
    cin >> s;
    while(s--){
		cin >> n >> p >> id; 
		if(p < 1e-9){ // p is very small.
			puts("0.0000"); continue;
		}
		double q = 1.0 - p; //fail
		double r = pow(q, n);
		double an = pow(q, id - 1) * p;
		printf("%.4lf\n", an/(1.0-r) + 1e-6); //捨位誤差
    }
    return 0;
}
