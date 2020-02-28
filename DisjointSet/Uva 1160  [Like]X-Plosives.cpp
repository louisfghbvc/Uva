#include <bits/stdc++.h>
#define N 100005
using namespace std;
int p[N];
int findp(int x){
    if(x == p[x])
        return x;
    return p[x] = findp(p[x]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a, b, cnt = 0;
    while(true){
        cnt = 0;
        for(int i = 0; i < N; ++i){
            p[i] = i;
        }
        if(scanf("%d %d", &a, &b) != 2)
            break;
        a = findp(a); b = findp(b);
        if(a == b){
            cnt++;
        }
        p[b] = a;
        while(cin >> a, a != -1){
            cin >> b;
            a = findp(a); b = findp(b);
            if(a == b){
                cnt++;
            }
            p[b] = a;
        }
        cout << cnt << endl;
    }
    return 0;
}
