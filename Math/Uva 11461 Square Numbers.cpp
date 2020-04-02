#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF && a+b){
    	int ans = 0;
    	for(int i = sqrt(a); i <= sqrt(b); ++i){
    		if(i*i >= a && i*i <= b) ans++;
    	}
    	printf("%d\n", ans);
    }
    return 0;
}

/**
//O(N)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF && a+b){
    	int ans = 0;
    	for(int i = a; i <= b; ++i){
    		int t = sqrt(i) + 1e-6;
    		if(t*t == i) ans++;
    	}
    	printf("%d\n", ans);
    }
    return 0;
}
**/
