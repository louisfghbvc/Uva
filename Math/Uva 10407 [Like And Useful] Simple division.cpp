//O(Nlog(num)), very impressive solution. gcd. think about example 14, 17, 23.
//14 = d*q1 + r --- (1)
//17 = d*q2 + r --- (2)
//23 = d*q3 + r --- (3)
//(2)-(1), (3)-(2)
//17 - 14 = d*(q2-q1)
//23 - 17 = d*(q3-q2)
//find d. so d is gcd num's difference.
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
