//A old problem but impressive, use recursive concept, last one num must 0, rebase num from 0
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
    	n--;
    	int m = 1;
    	for(;;++m){
    		int cur = 0;
    		for(int i = 1; i <= n; ++i){
    			cur = (cur + m) % i;
    		}
    		if(cur == 11) break;
    	}
    	cout << m << endl;
    }
    return 0;
}
