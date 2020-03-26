//Floyd find cycle
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int n, k, mask;

int resi(int x){
    LL tx = (LL)x * (LL)x; //can't use string don't know why.
    while(tx >= mask)
        tx /= 10;
    return tx;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        mask = 1;
        for(int i = 0; i < n; ++i)
            mask *= 10;
        LL s1 = k, s2 = k, mx = k; //slow, fast, max
        do{
            s1 = resi(s1);
            s2 = resi(s2);
            mx = max(s2, mx);
            s2 = resi(s2);
            mx = max(s2, mx);
        }while(s1 != s2);
        cout << mx << endl;
    }
    return 0;
}
