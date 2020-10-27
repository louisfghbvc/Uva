// number theory.
// remember some edge case. 0.
// just convert to base 10 than convert to wanted base.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int con(char c){
	return c-'A'+10;
}
char rcon(int c){
	if(c < 10) return '0'+c;
	return 'A'+c-10;
}
int main(){
    //freopen("out.txt", "w", stdout);
    string a;
    int b, c;
    while(cin >> a >> b >> c){
    	LL res = 0;
    	for(char ch: a){
    		if(isdigit(ch))
    			res = res * b + (ch-'0');
    		else
    			res = res * b + con(ch);
    	}
    	string sr = "";
    	if(!res) sr = "0";
    	while(res > 0){
    		sr.push_back(rcon(res%c));
    		res /= c;
    	}
    	if(sr.size() > 7){
            puts("  ERROR");
            continue;
    	}
    	while(sr.size() < 7) sr += " ";
    	reverse(sr.begin(), sr.end());
    	cout << sr << endl;
    }
    return 0;
}
