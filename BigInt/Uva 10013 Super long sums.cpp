#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d", &n);
    while(n--){
    	scanf("%d", &m);
    	int arr[m] = {0};
    	for(int i = 0; i < m; ++i){
            int a, b;
    		scanf("%d %d", &a, &b);
            arr[i] = a + b;
    	}
    	int carry = 0;
    	for(int i = m - 1; i >= 0; --i){
    		arr[i] += carry;
    		if(arr[i] > 9) carry = 1, arr[i] -= 10;
    		else carry = 0;
    	}
    	if(carry)
    		printf("1");
    	for(int i = 0; i < m; ++i){
    		printf("%d", arr[i]);
   		}
   		puts("");
   		if(n) puts("");
    }
    return 0;
}
