//0.080s.
//long long can more fast.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    while(cin >> n, n){
    	unordered_map<string, int> mp;
    	int mx = 0, sum = 0;
    	for(int i = 0; i < n; ++i){
    		vector<int> arr(5, 0);
    		for(int j = 0; j < 5; ++j){
    			cin >> arr[j];
    		}
    		sort(arr.begin(), arr.end());
    		string key = "";
    		for(const auto &c: arr)
    			key += to_string(c);
    		mx = max(++mp[key], mx);
    	}
    	for(auto x: mp){
    		if(x.second == mx) sum+=mx;
    	}
    	cout << sum << endl;
    }
    return 0;
}
