#include <bits/stdc++.h>
#define N 30005
using namespace std;
int p[N];
int findp(int x){
    if(x == p[x])
        return x;
    return p[x] = findp(p[x]);
}
int main()
{
    int n, c, a, b;
    cin >> n;
    for(int i = 0; i < 2*n; ++i){
        p[i] = i;
    }
    while(cin >> c >> a >> b, c + a + b){
        int a1 = findp(a), aen = findp(a + n);
        int b1 = findp(b), ben = findp(b + n);
        if(c == 1){
            if(a1 == ben || b1 == aen){
                cout << -1 << endl;
            }
            else{
                p[a1] = b1;
                p[aen] = ben;
            }
        }
        else if(c == 2){
            if(a1 == b1){
                cout << -1 << endl;
            }
            else{
                p[a1] = ben;
                p[aen] = b1;
            }
        }
        else if(c == 3){
            if(a1 == b1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if(c == 4){
            if(a1 == ben || b1 == aen)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
