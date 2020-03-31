#include <bits/stdc++.h>
using namespace std;

int id(char c){
	if(c >= 'a' && c <= 'z') 
		return c-'a';
	return c-'A';
}

int main(){
    int n;
    cin >> n;
    char c;
    int tot = 0;
    int fre[26]={};
    while(cin.get(c)){
    	if(isupper(c) || islower(c))
    		fre[id(c)]++, tot++;
    }
    for(; tot > 0; tot--){
		for(int i = 0; i < 26; ++i){
			if(tot == fre[i])
				cout << (char)(i+'A') << " " << fre[i] << endl;
		}
	}
    return 0;
}
/**input n absolutely no use.
4 
This is a test.
Count me 1 2 3 4 5. 
Wow!!!! Is this question easy? 
 Cut your coat according to your cloth. 
**/
