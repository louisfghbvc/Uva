//x = 0.1212...
//100x = 12.1212
//99x = 12
//x = 12/99                => 分母全為9

//0.51212...
//x = 0.1212...
//0.5 + 0.01x
//(50 + x) / 100           => 借100 所以之後要除100
//(50 + 12/99) / 100
//(50*99/99 + 12/99) / 100 =>通分
//last gcd

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string s;
    while(getline(cin, s) && s != "0"){
    	int len;
    	for(len = 2; len < s.size(); ++len) if(s[len] == '.') break;
    	LL ans_down = LLONG_MAX, ans_up;
    	for(int i = 2; i < len; ++i){
    		int nc = i-2; //non cycle length
    		LL cnt = 0, num = 0;
    		for(int k = i; k < len; ++k){
    			cnt = cnt*10 + (s[k]-'0');
    			num = num*10 + 9;
    		}
    		LL nc_cnt = 0;
    		for(int k = 2; k < i; ++k){
    			nc_cnt = nc_cnt*10 + (s[k]-'0');
    		}
    		cnt += nc_cnt * num;
    		for(int k = 0; k < nc; ++k)
    			num *= 10;
    		LL mg = __gcd(cnt, num);
    		cnt /= mg;
    		num /= mg;
    		if(num < ans_down){
    			ans_down = num;
    			ans_up = cnt;
    		}
    	}
    	printf("%lld/%lld\n", ans_up, ans_down);    	
    }
    return 0;
}
