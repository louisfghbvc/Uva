//only lower letter. so can do this.
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    while(cin >> a >> b){
    	int ac[27] = {};
    	int bc[27] = {};
    	for(int i = 0; i < a.size(); ++i) ac[a[i]-'a']++;
    	for(int i = 0; i < b.size(); ++i) bc[b[i]-'a']++;
    	
    	for(int i = 0; i < 26; ++i){
    		int comm = min(ac[i], bc[i]);
    		for(int j = 0; j < comm; ++j){
    			printf("%c", char(i+'a'));
    		}
    	}
    	puts("");
    }
    return 0;
}
