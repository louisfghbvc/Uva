//Counting sort. ascending order, max ascii
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    bool f = 0;
    while(getline(cin, str)){
    	if(f) puts("");
    	int fre[257] = {}, mxlen=0;
    	for(const auto c: str){
    		fre[c]++;
    		mxlen = max(fre[c], mxlen);
    	}
    	for(int k = 1; k <= mxlen; k++){
    		for(int i = 256; i >= 0; --i){
    			if(fre[i] == k)
    				printf("%d %d\n",i, k);
    		}
    	}
    	f=1;
    }
    return 0;
}
