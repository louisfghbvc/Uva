// Very Trick.
// if s[i]=='.', you will put next(mid) is scarecrow so that can cover 3.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int t, n, cas = 1;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        int cnt = 0;
        for(int i= 0; i < n; ++i){
            if(s[i] == '.'){
                cnt++;
                i += 2;
            }
        }
        printf("Case %d: %d\n", cas++, cnt);
    }
    return 0;
}
/**
3
3
.#.
11
...##....##
2
##

**/
