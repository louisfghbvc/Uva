//try to minimize the right interval. so sort from right, if from left, u will wrong, Greedy
#include <bits/stdc++.h>
#define N 1005
using namespace std;

struct point{
    double x, y;
    bool operator<(const point& p2) const{
        return x < p2.x;
    }
}p[N];

int main()
{
    int n, cas = 1;
    double d;
    while(cin >> n >> d){
        if(n == 0 && d == 0) break;

        bool flag = false;
        for(int i = 0; i < n; ++i){
            cin >> p[i].x >> p[i].y;
            if(p[i].y > d){
                flag = true;
            }
        }
        if(flag){
            printf("Case %d: %d\n", cas++, -1);
            continue;
        }
        sort(p, p + n);
        for(int i = 0; i < n; ++i){
            double x = p[i].x, y = p[i].y;
            double dif = sqrt(d*d - y*y);
            p[i] = {x - dif, x + dif};
        }
        int ans = 0;
        double cur = -1e60;
        for(int i = 0; i < n; ++i){
            if(p[i].x > cur){
                cur = p[i].y;
                ans++;
            }
            else{
                cur = min(cur, p[i].y);
            }
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
/*
3 2
1 2
-3 1
2 1
1 2
0 2
13 90
22 60
16 57
32 32
-48 37
-45 38
45 75
-4 9
-5 13
-23 25
-4 19
-45 82
9 58
18 41
0 0
*/
