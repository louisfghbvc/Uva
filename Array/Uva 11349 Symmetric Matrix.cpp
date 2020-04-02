//from head to tail.
#include <bits/stdc++.h>
#define N 105
using namespace std;
long long arr[N][N];
int main(){
    int t, n, cas = 1;
    char c;
    cin >> t;
    while(t--){
    	bool ok = 1;
    	cin >> c >> c >> n;
    	for(int i= 0; i < n; ++i)
    		for(int j= 0; j < n; ++j)
    			cin >> arr[i][j];
    	for(int i = 0; i < n && ok; ++i){
    		for(int j = 0; j < n && ok; ++j){
    			if(arr[i][j] < 0 || arr[i][j] != arr[n-i-1][n-j-1]) ok = 0;
    		}
    	}
    	printf("Test #%d: ", cas++);
    	puts(ok ? "Symmetric.": "Non-symmetric.");
    }
    return 0;
}
