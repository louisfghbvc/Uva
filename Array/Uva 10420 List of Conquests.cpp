#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
    while(cin >> n){
    	cin.ignore();
    	map<string, int> mp;
    	string str;
    	while(n--){
    		cin >> str;
    		mp[str]++;
    		getline(cin, str);
    	}
    	map<string, int> ::iterator x;
    	for(x = mp.begin(); x != mp.end(); x++)
    		cout << x->first << " " << x->second << endl;
    }
    return 0;
}
