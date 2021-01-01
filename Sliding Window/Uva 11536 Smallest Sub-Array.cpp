// Maintain window number size = k. use map or array.
// O(N).

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    arr[0] = 1, arr[1] = 2, arr[2] = 3;
    for(int i = 3; i < n; ++i)
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % m + 1;

    int mp[105] = {}, mp_size = 0;
    int res = -1;
    for(int r = 0, l = 0; r < n; ++r){
        if(mp_size < k && arr[r] <= k) {
            if(mp[arr[r]]++ == 0) mp_size++;
        }
        if(mp_size == k){
            if(res == -1) res = r-l+1;
            else res = min(res, r-l+1);
            while(mp_size >= k){
                res = min(res, r-l+1);
                int tmp = arr[l++];
                if(tmp > k) continue;
                if(--mp[tmp] == 0) mp_size--;
            }
        }
    }

    if(res < 0){
        cout << "sequence nai\n";
        return;
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        printf("Case %d: ", i);
        solve();
    }
}

