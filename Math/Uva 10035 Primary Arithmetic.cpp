#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    while(cin >> a >> b, a + b){
    	int c = 0, carry = 0;
		while(a > 0 || b > 0){
			int tmp = a%10 + b%10 + carry;
			if(tmp > 9) carry = 1, c++;
    		else carry = 0;
    		a/=10;
    		b/=10;
		}
    	
    	if(c > 1)
    		printf("%d carry operations.\n", c);
    	else if(c == 1)
    		printf("%d carry operation.\n", c);
    	else
    		printf("No carry operation.\n");
    }
    return 0;
}
