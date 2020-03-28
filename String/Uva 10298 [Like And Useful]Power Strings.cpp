//Kmp impressive. find second longest prefix-suffix. use length - that = smallest component. Tricky
#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int kt[N];
int main(){
    string s;
    while(getline(cin, s) && s != "."){
    	int len = s.size();
    	memset(kt, 0, sizeof kt);
    	int i = 0;
    	for(int j = 1; j < len; ){
    		if(s[i] == s[j]){
    			kt[j] = ++i;
    			j++;
    		}
    		else{
    			if(i != 0)
    				i = kt[i - 1];
    			else
    				j++;
    		}
    	}
    	int rem = len - kt[len - 1];
    	if(len % rem == 0)
    		cout << len/rem << endl;
    	else
    		cout << 1 << endl;
    }
    return 0;
}
/**
cdcdcdd
001234
**/
