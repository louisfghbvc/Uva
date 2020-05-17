// use lambda. binary search.
#include <bits/stdc++.h>
#define N 10005
using namespace std;

int arr[N];

int main()
{
    //freopen("out.txt", "w", stdout);
    int n, m;
    bool f = 0;
    while(cin >> n){
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        cin >> m;
        sort(arr, arr+n);
        auto bs = [](int key, int len){
            int l = 0, r = len-1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(arr[mid] == key){
                    return mid;
                }
                else if(arr[mid] < key){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            return -1;
        };
        int mn = INT_MAX, a, b;
        for(int k = 0; k < n; ++k){
            int sum = arr[k];
            int id = bs(m-sum, n);
            if(id != -1 && id != k){
                if(abs(id - k) < mn){
                    mn = abs(id-k);
                    a = arr[id];
                    b = arr[k];
                }
            }
        }
        if(a > b) swap(a, b);
        printf("Peter should buy books whose prices are %d and %d.\n", a, b);
        puts("");
    }
    return 0;
}
/**
2
40 40
80

5
10 2 6 8 4
10

**/
