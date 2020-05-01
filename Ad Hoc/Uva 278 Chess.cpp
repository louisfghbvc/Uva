// Simulate.
// Must know chess rule.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int t, n, m, sum;
    cin >> t;
    while(t--){
        char c;
        cin >> c >> n >> m;
        switch(c){
            case 'r':
                sum = min(n, m);
                break;
            case 'k':
                sum = 0;
                for(int i = 1; i <= n; ++i){
                    for(int j = i&1 ? 1: 2; j <= m; j += 2){
                        sum++;
                    }
                }
                break;
            case 'Q':
                sum = min(n, m);
                break;
            case 'K':
                sum = 0;
                for(int i = 1; i <= n; i += 2){
                    for(int j = 1; j <= m; j += 2){
                        sum++;
                    }
                }
                break;
        }
        cout << sum << endl;
    }
    return 0;
}
/*
2
r 6 7
k 8 8
*/
