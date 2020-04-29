// find mid.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, cas = 1, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a > b) swap(a, b);
        if(a > c) swap(a, c);
        if(b > c) swap(b, c);
        printf("Case %d: %d\n", cas++, b);
    }
    return 0;
}
