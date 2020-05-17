// math, binary search solve.
// x = [0, 1], if has root must f(0)*f(1) < 0. the line pass origin.
// first check 0 or 1 is ans or not.
// use fabs to know if is close 0.
// eps 1e-7. make value perfect.
// Nice problem.

#include <bits/stdc++.h>
using namespace std;

double p, q, r, s, t, u;
const double eps = 1e-7;
double func(double x){
    return p/exp(x) + q*sin(x)+
            r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    while(cin >> p >> q >> r >> s >> t >> u){
        double l = 0.0, r = 1.0, mid;
        double fa = func(l), fb = func(r);
        if(fabs(fa) < eps){
            puts("0.0000");
        }
        else if(fabs(fb) < eps){
            puts("1.0000");
        }
        else if(fa*fb < 0){
            while(eps <= r - l){
                mid = l + (r-l)/2;
                double v = func(mid);
                if(fabs(v) < eps)break;
                else if(v > 0) l = mid;
                else r = mid;
            }
            printf("%.4f\n", mid);
        }
        else puts("No solution");
    }
    return 0;
}
/**
0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1
**/
