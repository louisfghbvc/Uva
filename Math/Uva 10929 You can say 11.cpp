//11's rule odd sum - even sum == 11's multiple
#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(cin >> str && str != "0"){
    	int ods(0), evs(0);
    	for(int i = 0; i < str.size(); ++i){
    		if(i & 1) evs += str[i] - '0';
    		else ods += str[i] - '0';
    	}
    	if(abs(ods-evs) % 11 == 0)
    		printf("%s is a multiple of 11.\n", str.c_str());
    	else
    		printf("%s is not a multiple of 11.\n", str.c_str());
    }
    return 0;
}
