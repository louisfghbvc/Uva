// O(N^3). Enum. c = 10000. so x. y. z. < 100
#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;
bool check(){
    for(int x = -100; x <= 100; ++x){
        for(int y = -100; y <= 100; ++y){
            for(int z = -100; z <= 100; ++z){
                if(x == y || x == z || y == z) continue;
                if(x + y + z != a) continue;
                if(x*y*z != b) continue;
                if(x*x + y*y + z*z != c) continue;
                printf("%d %d %d\n", x, y, z);
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;

        if(!check()) puts("No solution.");
    }
    return 0;
}
/**
2
1 2 3
6 6 14
**/

// Solution2 O(N^2), Enum x, y. because z = A - x - y.

