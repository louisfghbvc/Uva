#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void mprint(LL x){
	if(!x) return;
	if(x < 100){
		cout << " " << x;
		return;
	}
	if(x >= 10000000){
		mprint(x/10000000);
		cout << " kuti";
		mprint(x%10000000);
	}
	else if(x >= 100000){
		mprint(x/100000);
		cout << " lakh";
		mprint(x%100000);
	}
	else if(x >= 1000){
		mprint(x/1000);
		cout << " hajar";
		mprint(x%1000);
	}
	else{
		mprint(x/100);
		cout << " shata";
		mprint(x%100);
	}
}

int main(){
    
    LL num; int cas = 1;
    while(cin >> num){
    	printf("%4d.", cas++);
    	if(num)
    		mprint(num);
    	else
    		cout << " 0";
    	puts("");
    }
    return 0;
}
/**
4589745/ 8973958
**/

