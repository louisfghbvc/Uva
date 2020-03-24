//careful negative num.
#include <bits/stdc++.h>
#define N 10005
using namespace std;

int arr[N];
int n, m, x;

bool com(int a, int b){
	int ma = a%m, mb = b%m;
	int oa = abs(a%2), ob = abs(b%2);
	if(ma == mb){
		if(oa == ob && oa)
			return a > b;
		else if(oa == ob && !oa)
			return a < b;
		return oa > ob;
	}
	return ma < mb;
}

int main(){
    while(cin >> n >> m, n + m){
    	for(int i = 0; i < n; ++i) cin >> arr[i];
    	sort(arr, arr+n, com);
    	printf("%d %d\n", n, m);
    	for(int i = 0; i < n; ++i)
    		cout << arr[i] << endl;
    }
   	printf("0 0\n");
    return 0;
}
