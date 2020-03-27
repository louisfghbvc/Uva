//O(N^3) 0.030s
#include <bits/stdc++.h>

using namespace std;

int a, b;
int func(int x, int y){
    return a*x + b*y;    
}

struct point{
    int x, y;
}p[120];

int main()
{
    int n;
    while(cin >> n, n){
        for(int i = 0; i < 2*n; ++i){
            cin >> p[i].x >> p[i].y;
        }
        for(a = -500; a <= 500; ++a){
            for(b = -500; b <= 500; ++b){
                int c = 0, cm = 0;
                for(int i = 0; i < 2*n; ++i){
                    if(func(p[i].x, p[i].y) > 0)
                        c++;
                    else if(func(p[i].x, p[i].y) < 0)
                        cm++;
                }
                if(c == n && cm == n){
                    cout << a << " " << b << endl;
                    a = b = 505;
                }
            }
        }
    }
}
