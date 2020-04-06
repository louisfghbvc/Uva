// check edge case. s == 9 or s == 0
#include <bits/stdc++.h>
using namespace std;

int degree(int s){
	if(s % 9 || !s) return 0;
	if(s == 9) return 1;
	int sum = 0;
	for(; s > 0; s /= 10)
		sum += s%10;
	return 1 + degree(sum);
}

int main(){
    string s;
    while(cin >> s && s != "0"){
    	int sum = 0;
    	for(int i= 0; i< s.size(); ++i)
    		sum += s[i]-'0';
    	if(sum%9)
    		printf("%s is not a multiple of 9.\n", s.c_str());
    	else
    		printf("%s is a multiple of 9 and has 9-degree %d.\n", s.c_str(), degree(sum));
    }
    return 0;
}
