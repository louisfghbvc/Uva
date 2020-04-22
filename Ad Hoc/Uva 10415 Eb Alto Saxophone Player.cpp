//Just Simulate, table a~g, A~G finger
//for each char, check press or not
#include <bits/stdc++.h>
using namespace std;

const char table[14][11] = {
	"0110000000",
	"0100000000",
	"0111001111",
	"0111001110",
	"0111001100",
	"0111001000",
	"0111000000",
	"1110000000",
	"1100000000",
	"0010000000",
	"1111001110",
	"1111001100",
	"1111001000",
	"1111000000"
};

int main(){
    int t;
    string s;
    cin >> t;
    cin.ignore();
    int mp[128] = {};
    for(char c = 'a'; c <= 'g'; ++c) mp[c] = c-'a';
    for(char c = 'A'; c <= 'G'; ++c) mp[c] = c-'A'+7;
    while(t--){
    	getline(cin, s);
    	int fre[10] = {}; bool vis[10] = {};
    	for(auto c : s){
    		for(int i = 0; i < 10; ++i){
    			if(table[mp[c]][i] == '1' && !vis[i]) vis[i] = 1, fre[i]++;
    			if(table[mp[c]][i] == '0') vis[i] = 0;
    		}
    	}
    	cout << fre[0];
    	for(int i = 1; i < 10; ++i) cout << " " << fre[i];
    	cout << endl;
    }
    return 0;
}
