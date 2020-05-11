// O(N^2). Simple Nest loop.
#include <bits/stdc++.h>
#define N 1005
using namespace std;

int arr[N];
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int sum = 0;
        for(int i = 1; i < n; ++i){
            int cnt = 0;
            for(int j = i-1; j >= 0; --j){
                if(arr[i] >= arr[j]) cnt++;
            }
            sum += cnt;
        }
        cout << sum << endl;
    }

    return 0;
}
