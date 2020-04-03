//from Big
#include <bits/stdc++.h>
#define N 42
using namespace std;

int arr[N];
void init(){
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < N; ++i){
		arr[i] = arr[i-1] + arr[i-2];
	}
}

LL func(int x){
	bool f = 0;
	for(int i = N - 1; i >= 2; --i){
		if(x >= arr[i]){
			putchar('1');
			f = 1;
			x -= arr[i];
		}
		else if(f && x < arr[i]) putchar('0');
	}
}

int main(){
    init();
   	int t, n;
   	cin >> t;
   	while(t--){
   		cin >> n;
   		printf("%d = ", n);
   		func(n);
   		puts(" (fib)");
   	}
    return 0;
}
