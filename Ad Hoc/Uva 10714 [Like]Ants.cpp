//Trick. two ants meet then just go throuth
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, l, n, x;
    cin >> t;
    while(t--){
        cin >> l >> n;
        int mimx = 0, mxmx = 0;
        for(int i = 0; i < n; ++i){
            cin >> x;
            mimx = max(min(x, l-x), mimx);
            mxmx = max(max(x, l-x), mxmx);
        }
        cout << mimx << " " << mxmx << endl;
    }
    return 0;
}
/*
2
10 3
2 6 7
214 7
11 12 7 13 176 23 191
*/
