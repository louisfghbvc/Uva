//useful strchr. cool. and in c/c++ pointer is array, same. can't const. shit compiler
#include <bits/stdc++.h>
using namespace std;
char *lst = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
int main(){
    string s;
    while(getline(cin, s)){
    	for(int i = 0; i < s.size(); ++i){
    		s[i] = tolower(s[i]);
    		char *tmp = strchr(lst, s[i]);
    		if(tmp)
    			printf("%c", lst[tmp - lst - 2]);
    		else
    			printf("%c", s[i]);
    	}
    	puts("");
    }
    return 0;
}
