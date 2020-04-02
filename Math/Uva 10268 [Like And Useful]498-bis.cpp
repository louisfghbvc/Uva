#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL pow2(LL a, LL b){
	if(b == 0) return 1;
	if(b & 1)
		return a*pow2(a*a, b/2);
	return pow2(a*a, b/2);
}

int main(){
    LL x, t;
    string s;
    while(cin >> x){
    	cin.ignore();
    	getline(cin, s);
    	stringstream ss(s);
    	
    	vector<LL> v; 
    	while(ss >> t) v.push_back(t);
    	
    	LL ans = 0;
    	for(int i = 0, n = v.size()-1; i < v.size()-1; ++i, n--){
    		ans += v[i] * n * pow(x, n - 1);
    	}
    	cout << ans << endl;
    }
    return 0;
}
/*
a0x^n + a1x^(n-1) +...+ an
*/
