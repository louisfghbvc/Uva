#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve(){
    // meet in middle
    // divide left, right half

    // use map to record the occurence values
    // try to combine them
    
    LL n, target;
    while(cin >> n >> target){
        vector<LL> arr(n);
        for(auto &it: arr)
            cin >> it;
        
        int h = n >> 1;
        unordered_map<LL, LL> left;
        for(int mask = 1; mask < 1<<h; ++mask){
            LL subset_sum = 0;
            for(int i = 0; i < h; ++i){
                if(mask >> i & 1)
                    subset_sum += arr[i];
            }
            left[subset_sum]++;
        }

        LL ans = left[target]; // right empty set
        left[0]++; // left empty set

        int r = n - h;
        for(int mask = 1; mask < 1<<r; ++mask){
            LL subset_sum = 0;
            for(int i = 0; i < r; ++i){
                if(mask >> i & 1)
                    subset_sum += arr[h + i];
            }
            if(left.count(target-subset_sum))
                ans += left[target-subset_sum];
        }
        cout << ans << "\n";

    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    solve();
}
