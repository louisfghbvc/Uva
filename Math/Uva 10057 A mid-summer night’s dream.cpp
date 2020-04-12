#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int arr[N];
int main(){
    int n;
    while(cin >> n){
    	for(int i=0; i < n; ++i)
    		cin >> arr[i];
    	sort(arr, arr+n);
    	int mid, mid2;
    	if(n % 2) mid = mid2 = arr[n/2];
    	else mid = arr[n/2-1], mid2 = arr[n/2];
    	int cnt = 0;
    	for(int i = 0; i < n; ++i)
    		if(arr[i] >= mid && arr[i] <= mid2) cnt++;
    	printf("%d %d %d\n", mid, cnt, mid2-mid+1);
    }
    return 0;
}
