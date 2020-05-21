// Counting sort. and set

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, cas = 1;
    while(cin >> n){
    	cin.ignore();
    	string str;
    	int fre[26], res = 0;
    	for(int i = 0; i < n; ++i){
    		memset(fre, 0, sizeof fre);
    		getline(cin, str);
    		for(const auto &c: str) fre[c-'a']++;
    		set<int> st;
    		bool ok = 1;
    		for(int i = 0; i < 26; ++i){
    			if(!fre[i]) continue;
    			if(st.count(fre[i])){
    				ok = 0;
    			}
    			st.insert(fre[i]);
    		}
    		if(ok && st.size() > 1) res++;
    	}
    	printf("Case %d: %d\n", cas++, res);
    }
    return 0;
}
