#include <bits/stdc++.h>
#define N 46342
using namespace std;

bool np[N];
vector<int> pr;
bool isP(int x){
	if(x < N)
		return !np[x];
	for(int i = 0; i < pr.size(); ++i){
		if(x % pr[i] == 0) return false;
	}
	return true;
}

void init(){
	np[0] = np[1] = true;
	for(int i = 2; i < N; ++i){
		if(!np[i]){
			pr.push_back(i);
			for(int j = 2*i; j < N; j+=i){
				np[j] = true;
			}
		}
	}

}

int main(){
    int l, u;
    init();
    while(cin >> l >> u){
    	int p1(0), p2(0), mn(INT_MAX), mx(INT_MIN);
    	int a, b, c, d;
    	for(int i = l; i <= u; ++i){
    		if(isP(i)){
    			if(p1 <= p2) p1 = i;
    			else p2 = i;
    			//cout << p1 << " " << p2 << endl;
    		}
    		if(p1 && p2){
    			int dis = abs(p2 - p1);
    			if(dis < mn){
    				mn = dis;
    				a = min(p1, p2);
    				b = max(p1, p2);
    			}
    			if(dis > mx){
    				mx = dis;
    				c = min(p1, p2);
    				d = max(p1, p2);
    			}
    		}
    	}
    	if(mn == INT_MAX)
    		printf("There are no adjacent primes.\n");
    	else
    		printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
    }
    return 0;
}
