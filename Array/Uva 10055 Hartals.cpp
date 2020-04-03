#include <bits/stdc++.h>
using namespace std;

int arr[105];
int main(){
    int t, n, p;
    cin >> t;
    while(t--){
    	cin >> n >> p;
    	for(int i = 0; i < p; ++i){
    		cin >> arr[i];
    	}
    	bool vis[3655] = {};
    	for(int i = 0; i < p; ++i){
    		for(int j = arr[i]; j <= n; j+=arr[i]){
    			vis[j] = 1;
    		}
    	}
    	int ans = 0, day = 0;
    	for(int i = 1; i <= n; ++i, ++day){
    		day %= 7;
    		if(day != 5 && day != 6 && vis[i]) ans++;
    	}
    	cout << ans << endl;
    }
    return 0;
}
