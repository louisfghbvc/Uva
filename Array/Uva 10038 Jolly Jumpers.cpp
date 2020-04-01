#include <bits/stdc++.h>
#define N 3005
using namespace std;
int arr[N];
int main(){
    int n;
   	while(cin >> n){
   		for(int i = 0; i < n;++i) cin >> arr[i];
   		bool vis[N] = {};
   		bool ok = 1;
   		for(int i = 1; i < n; ++i)
   			vis[abs(arr[i] - arr[i-1])] = 1;
   		for(int i = 1; i < n; ++i)
   			ok &= vis[i];
   		puts(ok ? "Jolly": "Not jolly");
   	}
    return 0;
}
