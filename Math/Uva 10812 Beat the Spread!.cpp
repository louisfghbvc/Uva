//check may be redundant. just easy.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, s, d;
    cin >> n;
    while(n--){
    	cin >> s >> d;
    	int a = (s+d)/2, b;
    	b = s - a;
    	if(b < 0 || a < 0 || a < b || a-b != d)
    		puts("impossible");
    	else
    		cout << a << " " << b << endl;
    }
    return 0;
}
/*
s = a+b
d = a-b, s > d
a = 2 
*/
