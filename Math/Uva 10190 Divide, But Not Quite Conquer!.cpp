//n < m. important.
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL n, m;
    while(cin >> n >> m){
    	vector<LL> seq;
    	if(m <= 1 || n < m){
    		cout << "Boring!\n";
    		continue;
    	}
    	if(!b){
    		cout << seq[0];
    		for(int i = 1; i < seq.size(); ++i){
    			cout << " " << seq[i];
    		}
    	}
    	else cout << "Boring!";
    	cout << "\n";
    }
    return 0;
}
