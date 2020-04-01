//O(Nlog(num)), very impressive solution. gcd. think about example 14 and 23.
//14 + 9, dif = 9
//23    , after they cut 9*x, remain is same, this is ans.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int arr[1005];
    while(1){
    	int id = 0;
    	cin >> n;
    	if(!n) break;
    	arr[id++] = n;
    	while(cin >> n, n){
    		arr[id++] = n;
    	}
    	int ans = abs(arr[0] - arr[1]);
    	for(int i = 2; i < id; ++i)
    		ans = __gcd(ans, abs(arr[i] - arr[i-1]));
    	cout << ans << endl;
    }
    return 0;
}
