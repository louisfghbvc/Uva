#include <bits/stdc++.h>
using namespace std;

int toint(string s){
	int ans = 0;
	for(int i = 0; i < s.size(); ++i)
		ans = ans*2 + s[i]-'0';
	return ans;
}

int main(){
    int n;
    string s1, s2;
    cin >> n;
    for(int i = 1; i <= n; ++i){
    	cin >> s1 >> s2;
    	int a = toint(s1), b = toint(s2);
    	int gcd = __gcd(a, b);
    	printf("Pair #%d: ", i);
    	puts(gcd == 1 ? "Love is not all you need!" : "All you need is love!");
    }
    return 0;
}
