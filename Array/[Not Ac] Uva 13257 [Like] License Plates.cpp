// O(26^3 * log(N)).
// timelimit.
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >>t;
    string s;
    while(t--){
    	cin >> s;
    	vector<int> pos[26];
    	for(int i = 0; i < s.size(); ++i){
    		pos[s[i]-'A'].push_back(i);
    	}
    	int res = 0;
    	for(char a = 'A'; a <= 'Z'; ++a){
    		for(char b = 'A'; b <= 'Z'; ++b){
    			for(char c = 'A'; c <= 'Z'; ++c){
    				char t[3] = {a, b, c};
    				int j = 0;
    				int x = -1;
    				for(; j < 3; ++j){
    					int v = t[j] - 'A';
    					auto it = upper_bound(pos[v].begin(), pos[v].end(), x);
    					if(it != pos[v].end()) x = *it;
    					else break;
    				}
    				if(j == 3) res++;
    			}
    		}	
    	}
    	cout << res << endl;
    }
    return 0;
}
/**
*26*26*26
**/
