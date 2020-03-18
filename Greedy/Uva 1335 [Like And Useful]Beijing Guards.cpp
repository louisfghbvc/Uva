//Cycle length is even, then ans is max neightbor.Otherwise, ans is binary search a mid, take from head or tail. nice problem
#include <bits/stdc++.h>
#define N 100005
using namespace std;

int arr[N], lt[N], rt[N], n;

bool check(int m){
    int l = arr[0], r = m - arr[0];
    lt[0] = l, rt[0] = 0;
    for(int i = 1; i < n; ++i){
        if(i % 2){ // odd
            lt[i] = min(l - lt[i - 1], arr[i]);
            rt[i] = arr[i] - lt[i];
        }
        else{
            rt[i] = min(r - rt[i - 1], arr[i]);
            lt[i] = arr[i] - rt[i];
        }
    }
    return lt[n - 1] == 0;
}

int main()
{
    while(cin >> n, n){
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        if(n == 1){
            cout << arr[0] << endl;
            continue;
        }
        arr[n] = arr[0];
        int l = 0, r = N * 3;
        for(int i = 0; i < n; ++i){
            l = max(l, arr[i] + arr[i + 1]);
        }
        if(n % 2 == 0){
            cout << l << endl;
            continue;
        }
        //cout << l << " " << r << endl;
        int ret = l;
        while(l <= r){
            int mid = (l + r)/2;
            if(check(mid)){
                r = mid - 1;
                ret = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ret << endl;

    }
    return 0;
}
/**
3
4
2
2
5
2
2
2
2
2
5
1
1
1
1
1
0
**/
