#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int p[N];
int findp(int x){
    if(x == p[x]) return x;
    return p[x] = findp(p[x]);
}
void con(int x, int y){
    x = findp(x); y = findp(y);
    p[y] = x;
}
bool lk(int x, int y){
    x = findp(x); y = findp(y);
    return p[x] == p[y];
}

int main()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n; cin.ignore();
        for(int i = 1; i <= n; ++i) p[i] = i;
        string s;
        int sc = 0, nsc = 0;
        while(getline(cin, s) && s.size()){
            stringstream ss(s);
            char c; int x, y;
            ss >> c >> x >> y;
            if(c == 'c') con(x, y);
            if(c == 'q'){
                if(lk(x, y)) sc++;
                else nsc++;
            }
        }
        printf("%d,%d\n", sc, nsc);
        if(t) puts("");
    }
    return 0;
}
