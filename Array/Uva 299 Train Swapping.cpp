//Can use merge sort.
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int arr[n+2];
		for(int i = 0; i < n; ++i){
			cin >> arr[i];
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j){
				if(arr[i] > arr[j]) cnt++;
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", cnt);
	}
    return 0;
}
