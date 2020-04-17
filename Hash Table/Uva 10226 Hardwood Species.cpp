//map is useful.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d\n\n", &t);
    while(t--){
    	string s;
    	map<string, int> mp;
    	int total = 0;
   	 	while(getline(cin, s)){
   	 		if(s == "") break;
   	 		mp[s]++;
   	 		total++;
    	}
    	for(auto m: mp){
    		printf("%s %.4f\n", m.first.c_str(), (double)m.second/total*100.0);
    	}
    	if(t) puts("");
    }
    
    return 0;
}
