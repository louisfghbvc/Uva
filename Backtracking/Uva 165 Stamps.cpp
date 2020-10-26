// Fun problem, just need long time to understand the problem statement.
// DFS, and backtracking use BF. tricky is the check and dfs.
// check not optimal can use dp. but input is small so is fine.

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> ans;
int mx = 0;
int h, k;

bool check(int target, int sum, int i, int total){
	if(sum == target) return true;
	if(i == arr.size() || total == h) return false;
	else if(check(target, sum, i+1, total)) return true;
	else if(check(target, sum+arr[i], i, total+1)) return true;
	return false;
}

void dfs(int cur){
	if(cur-1 > mx){
		mx = cur-1;
		ans = arr;
	}
	if(check(cur, 0, 0, 0)){
		dfs(cur+1);
	}
	if(arr.size() < k){
		arr.push_back(cur);
		dfs(cur+1);
		arr.pop_back();
	}
}

int main(){
   	while(cin >> h >> k, h+k){
   		mx = 0;
   		dfs(1);
   		for(int x: ans)
            printf("%3d", x);
   		printf(" ->%3d\n", mx);
   	}
    return 0;
}
