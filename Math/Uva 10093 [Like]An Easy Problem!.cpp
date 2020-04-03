//impressive use string as int array, then mod. 2-62 base
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin, s)){
    	int mn = 1, st = 0;
    	bool ok = 1;
    	if(s[0] == '-' || s[0] == '+') st++;
    	for(int i = st; i < s.size(); ++i){
    		if(s[i] >= '0' && s[i] <= '9') s[i] = s[i] - '0';
    		else if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 10;
    		else if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 36;
    		else ok = 0;
    		mn = max(mn, (int)s[i]);
    	}
    	mn++;
    	int i;
    	for(i = mn; i <= 62 && ok; ++i){
    		int tmp = 0, k = i-1;
    		for(int j = st; j < s.size(); ++j){
    			tmp = tmp*i + (int)s[j];
    			tmp %= k;
    		}
    		if(tmp == 0) break;
    	}
    	if(!ok || i == 63)
    		cout << "such number is impossible!\n"; 
    	else
    		cout << i << endl;
    }
    return 0;
}
