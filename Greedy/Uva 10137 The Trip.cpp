//Tricky. without using float. use mod to remain. decreasing
#include <bits/stdc++.h>
#define N 1005
using namespace std;

int arr[N];
int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
    	int sum = 0;
    	for(int i = 0; i < n; ++i){
    		int a, b;
    		scanf("%d.%d", &a, &b);
    		arr[i] = 100*a + b;
    		sum += arr[i];
    	}
    	int re = sum%n, ans = 0;
    	sum/=n;
    	sort(arr, arr+n, greater<int>());
    	for(int i = 0; i < n; ++i){
    		if(i < re)
    			ans += abs(arr[i] - sum - 1);
    		else
    			ans += abs(arr[i] - sum);
    	}
    	printf("$%.2lf\n", ans/200.0);
    }
    return 0;
}
