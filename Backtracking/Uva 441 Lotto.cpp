// Solution1 BruteForce. 6 for loop. 
#include <bits/stdc++.h>
#define N 105
using namespace std;

int main(){
    int n;
    bool f = 0;
    while(cin >> n, n){
        if(f) puts("");
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                for(int k = j+1; k < n; ++k){
                    for(int l = k+1; l < n; ++l){
                        for(int m = l+1; m < n; ++m){
                            for(int o = m+1; o < n; ++o){
                                printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[k], arr[l], arr[m], arr[o]);
                            }
                        }  
                    }   
                }
            }
        }
        f = 1;
    }

    return 0;
}

// Solution2 BackTracking. Simple.
