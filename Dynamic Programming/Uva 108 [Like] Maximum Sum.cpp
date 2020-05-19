// solution1. 2D Prefix. O(N^4)
#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int pre[105][105];
int main()
{
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n){
        memset(pre, 0, sizeof pre);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> arr[i][j];
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + arr[i-1][j-1];
            }
        }
        int mx = INT_MIN;
        for(int r = 0; r <= n; ++r){
            for(int c = 0; c <= n; ++c){
                for(int i = r; i <= n; ++i){
                    for(int j = c; j <= n; ++j){
                        mx = max(mx, pre[i][j]-pre[r][j]-pre[i][c]+pre[r][c]);
                    }
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}
/**
4
0 -2 -7 0 9 2 -6 2
-4 1 -4 1 -1
8 0 -2
**/

// Solution2 2D dp. O(N^3)
