//Just encode and decode. RFC 2045
#include <bits/stdc++.h>
using namespace std;
const char* lst = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

bool input(string &s){
	s.clear();
	char c;
	while(cin.get(c) && c != '#'){
		if(strchr(lst, c))
			s += c;
	}
	return !s.empty();
}

int main(){
   	for(string s; input(s); putchar('#')){
   		//cout << s << endl;
   		for(int i = 0; i < s.size(); i += 4){
   			char now[] = {s[i], s[i+1], s[i+2], s[i+3]};
   			int val[4], word[3];
   			for(int k = 0; k < 4; ++k)
   				val[k] = (strchr(lst, now[k]) - lst)%64; 
   			word[0] = val[0] << 2 | val[1] >> 4;
   			word[1] = (val[1]%16) << 4 | val[2] >> 2;
   			word[2] = (val[2]%4) << 6 | val[3];
   			for(int k = 0; k < 3; ++k)
   				if(now[k+1] != '=')
   					printf("%c", word[k]);
   		}
   	}
   	puts("");
    return 0;
}
