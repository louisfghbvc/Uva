// Enum all time. O(N^2).
// use queue. greedy take as max load as possible

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c, n, t, m, x;
    cin >> c;
    while(c--){
        cin >> n >> t >> m;
        queue<int> arr;
        for(int i = 0; i < m; ++i){
            cin >> x;
            arr.push(x);
        }
        int mn = INT_MAX, ans = INT_MAX;
        for(int tt = 0; tt < 1440; tt++){
            queue<int> tmp = arr;
            int lans = 0, now = tt;
            while(!tmp.empty()){
                if(tmp.front() > now) now = tmp.front();
                int k = 0;
                while(!tmp.empty() && tmp.front() <= now && k < n){
                    tmp.pop();
                    k++;
                }
                now += t;
                lans++;
                if(tmp.empty()) break;
                now += t;
            }
            if(mn >= now){
                mn = now;
                ans = min(ans, lans);
            }
        }
        cout << mn << " " << ans << endl;
    }
    return 0;
}
