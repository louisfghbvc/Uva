//O(NloglogN)
#include <bits/stdc++.h>
#define N 1000005
using namespace std;

bool np[N];
void init(){
	for(int i = 2; i <= sqrt(N); ++i){
		if(!np[i]){
			for(int j = i*2; j < N; j+=i)
				np[j] = 1;
		}
	}
}

int rev(int x){
	int res = 0;
	while(x > 0){
		res = res*10 + x%10;
		x/=10;
	}
	return res;
}

int main(){
    int n;
    init();
    while(cin >> n){
    	int ren = rev(n);
    	if(np[n]){
    		printf("%d is not prime.\n", n);
    	}
    	else{
    		if(np[ren] || ren == n)
    			printf("%d is prime.\n", n);
    		else
    			printf("%d is emirp.\n", n);
    	}
    }
    return 0;
}
