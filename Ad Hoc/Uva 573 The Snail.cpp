// Simulate. Snail
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h, u, d, f;
    while(cin >> h >> u >> d >> f, h){
        double now_h = 0, drop = u*(f/100.0);
        int day = 1;
        while(1){
            if(u > 0)
                now_h += u;
            if(now_h > h){
                printf("success on day %d\n", day);
                break;
            }
            now_h -= d;
            if(now_h < 0.0){
                printf("failure on day %d\n", day);
                break;
            }
            u -= drop;
            day++;
        }
    }
    return 0;
}
/*
6 3 1 10
10 2 1 50
50 5 3 14
50 6 4 1
50 6 3 1
1 1 1 1
0 0 0 0
*/
