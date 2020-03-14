//Tricky, two frog jump jump together.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, d, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> d;
        bool small[n + 2] = {};
        vector<int> arr(n + 2, 0);
        for(int i = 0; i < n; ++i){
            char c;
            cin >> c; cin.ignore(); cin >> arr[i];
            if(c == 'S')
                small[i] = 1;
        }
        arr[n] = d;
        int a = 0, b = 0, dif = 0;
        for(int i = 0; i <= n; ++i){
            if(small[i]){
                if(a < b){
                    dif = max(dif, arr[i] - a);
                    a = arr[i];
                }
                else{
                    dif = max(dif, arr[i] - b);
                    b = arr[i];
                }
            }
            else{
                dif = max({dif, arr[i] - a, arr[i] - b});
                a = b = arr[i];
            }
        }
        printf("Case %d: %d\n", cas++, dif);
    }
    return 0;
}
