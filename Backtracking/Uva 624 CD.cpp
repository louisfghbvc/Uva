// Just find a subset. may have many ans. Enum.
// O(2^t * t). slow ans.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    while(cin >> n >> t){
        int arr[t];
        for(int i = 0; i < t; ++i) cin >> arr[i];
        int record = 0, mx = 0;
        for(int i = 0; i < (1<<t); ++i){
            int sum = 0;
            for(int j = 0; j < t; ++j){
                if((1<<j) & i) sum += arr[j];    
            }
            if(sum > n) continue;
            if(sum > mx){
                mx = sum;
                record = i;
            }
        }
        for(int i = 0; i < t; ++i){
            if((1<<i) & record){
                printf("%d ", arr[i]);
            }
        }
        printf("sum:%d\n", mx);
    }
}

// Solution2 01 bag. Dp, Fast ans.
