// Trick. Simulate left and right
// Count it.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, l, m;
    cin >> t;
    while(t--){
        cin >> l >> m;
        l *= 100;
        queue<int> L, R;
        for(int i = 0; i < m; ++i){
            int x; string s;
            cin >> x >> s;
            if(s[0] == 'l') L.push(x);
            else R.push(x);
        }
        int res = 0;
        bool dir = 0;
        while(!L.empty() || !R.empty()){
            res++;
            int sum = 0;
            if(dir){
                while(!R.empty() && sum + R.front() <= l)
                    sum += R.front(), R.pop();
            }
            else{
                while(!L.empty() && sum + L.front() <= l)
                    sum += L.front(), L.pop();
            }
            dir ^= 1;
        }
        cout << res << endl;
    }
    return 0;
}
