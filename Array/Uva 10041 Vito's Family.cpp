//just find middle place
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
    	cin >> n;
    	int arr[n + 2];
    	for(int i = 0; i < n; ++i) cin >> arr[i];
    	
    	int dis = 0, jud;
    	sort(arr, arr+n);
    	if(n % 2 == 0)
    		jud = (arr[n/2-1]+arr[n/2])/2;
    	else
    		jud = arr[n/2];
    	for(int i = 0; i < n; ++i){
    		dis += abs(jud - arr[i]);
    	}
    	cout << dis << endl;
    }
    return 0;
}
