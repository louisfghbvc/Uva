// Just find a subset. may have many ans. Enum.
// O(2^t * t). slow ans. 0.520s
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
// any path are correct. 0s.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    while(cin >> n >> t){
        int arr[t], cd[n+1] = {};
        bool dp[n+1] = {};
        for(int i = 0; i < t; ++i) cin >> arr[i];
        dp[0] = 1;
        for(int i = 0; i < t; ++i){
            for(int j = n; j >= arr[i]; --j){
                if(dp[j-arr[i]] == 1 && dp[j] == 0){
                    dp[j] = 1;
                    cd[j] = arr[i];
                }    
            }
        }
        int st = n;
        while(!dp[st]) st--;
        for(int k = st; k; k -= cd[k]){
            printf("%d ", cd[k]);    
        }
        printf("sum:%d\n", st);
    }
}
