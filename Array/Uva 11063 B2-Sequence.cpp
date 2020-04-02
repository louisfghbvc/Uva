#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main(){
    int n, cas = 1, t;
    while(cin >> n){
    	bool ok = 1;
    	for(int i = 0; i < n; ++i){
    		cin >> arr[i];
    	}
    	bool vis[20005] = {};
    	for(int i = 0; i < n && ok; ++i){
    	   for(int j = i; j < n && ok; ++j){
    	       if(vis[arr[i]+arr[j]]) ok = 0;
    	       vis[arr[i]+arr[j]] = 1;
    	   }    
    	}
    	printf("Case #%d: ", cas++);
    	puts(ok ? "It is a B2-Sequence.\n": "It is not a B2-Sequence.\n");
    }
    return 0;
}
