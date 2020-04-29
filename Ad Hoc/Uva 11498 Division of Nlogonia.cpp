// Simple
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n, m;
    while(cin >> k, k){
        cin >> n >> m;
        int x, y;
        for(int i = 0; i < k; ++i){
            cin >> x >> y;
            if(x == n || y == m){
                puts("divisa");
            }
            else if(x < n && y > m){
                puts("NO");
            }
            else if(x > n && y > m){
                puts("NE");
            }
            else if(x < n && y < m){
                puts("SO");
            }
            else{
                puts("SE");
            }
        }
    }
    return 0;
}
