// Circle. Watch out > 180
#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main()
{
    double l, d, r = 6440;
    string s;
    
    while(cin >> l >> d >> s){
        double c, a = l + r, arc = 0.0;
        if(s == "min"){
             d /= 60.0;
        }
        if(d >= 180.0) d = 360 - d;
        c = sqrt(2*pow(a, 2) - 2*pow(a, 2)*cos(d*(PI/180.0)));
        arc = 2*a*PI*(d/360); 
        printf("%.6f %.6f\n", arc, c);    
    }
}
/*
1 degree = 60min
c^2 = a^2 + b^2 - 2abcosd
1 degree = PI/180
*/
