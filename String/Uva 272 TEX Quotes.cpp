#include <bits/stdc++.h>
using namespace std;
int main(){
	string s = "", t;
    while(getline(cin, t)) s += t+"\n";
    bool f = 1;
    for(int i = 0; i < s.size(); ++i){
    	if(s[i] == '\"'){
    		if(f) putchar('`'), putchar('`');
    		else putchar('\''), putchar('\'');
    		f ^= 1;
    	}
   		else putchar(s[i]);
    }
    
    return 0;
}
