//tricky, and mp[a] = mp.size(), can't do that, don't know why..
#include <bits/stdc++.h>
#define N 1005
using namespace std;

struct com {
    int price, qt;
};
vector<com> v[N];

int main()
{
    int t, n, money;
    cin >> t;
    while(t--){
        map<string, int> mp;
        int l = 0, r = 0, id = 0;

        cin >> n >> money;

        for(int i = 0; i < n; ++i)
            v[i].clear();
        for(int i = 0; i < n; ++i){
            string a, b;
            int p, q;
            cin >> a >> b >> p >> q;
            if(!mp.count(a)){
                mp[a] = id++;
            }
            v[mp[a]].push_back({p, q});
            r = max(r, q);
        }

        int ans = 0;
        while(l <= r){
            int mid = (l + r)/2;
            int sum = 0;
            for(int i = 0; i < id; ++i){
                int cheap = 1e9;
                for(int j = 0; j < v[i].size(); ++j){
                    if(v[i][j].qt >= mid){
                        cheap = min(cheap, v[i][j].price);
                    }
                }
                sum += cheap;
                if(sum > money)
                    break;
            }
            if(sum > money){
                r = mid - 1;
            }
            else{
                l = mid + 1, ans = max(mid, ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1
18 800
processor 3500_MHz 66 5
processor 4200_MHz 103 7
processor 5000_MHz 156 9
processor 6000_MHz 219 12
memory 1_GB 35 3
memory 2_GB 88 6
memory 4_GB 170 12
mainbord all_onboard 52 10
harddisk 250_GB 54 10
harddisk 500_FB 99 12
casing midi 36 10
monitor 17_inch 157 5
monitor 19_inch 175 7
monitor 20_inch 210 9
monitor 22_inch 293 12
mouse cordless_optical 18 12
mouse microsoft 30 9
keyboard office 4 10
*/
