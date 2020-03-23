//擴展歐幾里得演算法
#include <bits/stdc++.h>
using namespace std;

int x, y;
int ext(int a, int b){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	int r = ext(b, a%b);
	int py = y;
	y = x - a / b * y;
	x = py;
	return r;
}

int main(){
    int a, b;
    while(cin >> a >> b){
    	int g = ext(a, b);
    	printf("%d %d %d\n", x, y, g);
    }
    return 0;
}
/* 
遞迴推演
ax + by = gcd(a, b) = gcd(b, a%b);
ax + by = ay' + b(x'-a/by')
x = y'
y = x' - a/b*y'
*/
