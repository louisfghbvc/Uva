// Tricky. O(NlogN)
// 1 1
// 2 2 2
// 3
// ==> (1,2,3), (1, 2), (2). but minimum each bag size
// ==> (1,2), (1, 2), (2, 3). 
// and size k must be fre highest.
// so that k pieces. i = 0~k, j = for(i, n, i+k)
// so size can be minimum, and each can pack another.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int n;
    bool f=0;
    while(cin >> n, n){
        if(f) puts("");
        int arr[n+5] = {};
        for(int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr+n);
        int k = 0, cnt = 1;
        for(int i = 1; i <= n; ++i){
            if(arr[i] == arr[i-1]) cnt++;
            else{
                k = max(cnt, k);
                cnt = 1;
            }
        }
        cout << k << "\n";
        for(int i = 0; i < k; ++i){
            cout << arr[i];
            for(int j = i+k; j < n; j+=k){
                cout <<  " " << arr[j];
            }
            cout << "\n";
        }
        f= 1;
    }
    return 0;
}
/**
6
1 2 2 2 2 2
0
**/
