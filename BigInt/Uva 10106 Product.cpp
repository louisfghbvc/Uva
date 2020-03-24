//O(N^2)
#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    int a[500] = {0}, b[500] = {0};
    while(getline(cin, input)){
    	int alen = input.size(), blen, clen;
    	for(int i = 0; i < alen; ++i){
    		a[i] = input[alen - 1 - i] - '0';
    	}
    	getline(cin, input);
    	blen = input.size();
    	for(int i = 0; i < blen; ++i){
    		b[i] = input[blen - 1 - i] - '0';
    	}
    	
    	clen = alen + blen;
    	int ans[clen] = {0};
    	for(int i = 0; i < alen; ++i){
    		for(int j = 0; j < blen; ++j){
    			ans[i + j] += a[i]*b[j];
    			ans[i + j + 1] += ans[i + j]/10;
    			ans[i + j] %= 10;
    		}
    	}
    	
    	while(clen > 1 && !ans[clen-1]) clen--;
    	
    	for(int i = clen - 1; i >= 0; --i){
    		printf("%d", ans[i]);
    	}
    	printf("\n");
    }
    return 0;
}
