//Use map.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    map<string, int> mp;
    for(int i = 0; i < m; ++i){
    	string str; int val;
    	cin >> str >> val;
    	mp[str] = val;
    }
    cin.ignore();
    string tmp;
    while(n--){
    	int ans = 0;
    	while(getline(cin, tmp)){
			if(tmp == ".") break;
			stringstream ss(tmp);
			while(ss >> tmp){
    			ans += mp[tmp];
    		}
    	}
    	cout << ans << endl;
    }
    return 0;
}
/**
administer 100000
spending 200000
manage 50000
responsibility 25000
expertise 100
skill 50
money 75000
**/
