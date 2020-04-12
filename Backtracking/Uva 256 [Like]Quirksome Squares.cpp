//O(N), build table, printf 0*d digit control
#include <bits/stdc++.h>
using namespace std;
const int d[] = {0, 10, 100, 1000, 10000};
vector<int> arr[5];
void init(){
	for(int i = 0; i < 10000; ++i){
		int sq = i*i;
		for(int j = 1; j < 5; ++j){
			if(i == d[j]) continue;
			int x = sq/d[j] + sq%d[j];
			if(x*x == sq){
				arr[j].push_back(sq);
			}
		}
	}
}

int main(){
	int n;
	init();
	while(cin >> n){
		int id = n/2;
		for(int i = 0; i < arr[id].size(); ++i){
			printf("%0*d\n", n, arr[id][i]);
		}
	}
    return 0;
}
