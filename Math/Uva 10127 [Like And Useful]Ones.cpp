//Tricky. mod
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
    	int ans = 1;
    	int one = 1;
    	while(one % n){
    		one = (10 * one + 1) % n;
    		ans++;
    	}
    	cout << ans << endl;
    }
    return 0;
}
/*
EX: 
1 % 3 = 1 => 1 = 1 (mod 3)
11 % 3 = 2 => 11 = 2 (mod 3)    
111 % 3 = 0 => 111 = 21 (mod 3)


becasue 111 = 11 * 10 + 1, 21 = 2 * 10 + 1; 
*/
