// Calculate clock.
// maintain positive and 180's degree
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int h, m;
    while(scanf("%d:%d", &h, &m) != -1, h + m){
        if(h == 12) h = 0;
        double degree = abs((h*30.0 + (double)m/2.0) - (double)m*6);
        if(degree > 180.0) degree = 360.0-degree;
        printf("%.3f\n", degree);
    }
    return 0;
}
/*
12:00
9:00
8:10
0:00

1: 12
*/
