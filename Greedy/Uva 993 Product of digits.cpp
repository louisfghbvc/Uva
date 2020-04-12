//From big digit
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
    	cin >> n;
    	if(n <= 1){
    		cout << n << endl; continue;
    	}
    	stack<int> fac; 
    	for(int i = 9; i >= 2; --i){
    		while(n % i == 0){
    			fac.push(i);
    			n /= i;
    		}
    	}
    	if(n > 9){
    		cout << -1 << endl;
    	}
    	else{
    		while(!fac.empty()){
    			cout << fac.top(); fac.pop();
    		}	
    		cout << endl;
    	}
    }
    return 0;
}
