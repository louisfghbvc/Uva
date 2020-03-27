//Tricky. table all data
#include <bits/stdc++.h>
#define N 1005
using namespace std;

int num[3*N] = {1};
int sum[1005] = {1, 1};
int main(){
    int n, digit = 1;
    for(int i = 2; i <= 1000; ++i){
    	for(int j = 0; j < digit; ++j){
    		num[j] *= i;
    	}
    	for(int j = 0; j < digit; ++j){
    		num[j + 1] += num[j]/10;
    		if(j + 1 >= digit && num[j + 1] > 0) ++digit;
    		num[j] %= 10;
    		sum[i] += num[j];
    	}
    }
    while(cin >> n){
    	cout << sum[n] << endl;
    }
    return 0;
}
