// Just simulate all case.
// Card game.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("out.txt", "w", stdout);
    int a, b, c, x, y;
    while(cin >> a >> b >> c >> x >> y, a+b+c+x+y){
        bool vis[53] = {};
        vis[a] = vis[b] = vis[c] = vis[x] = vis[y] = 1;
        bool ok = 0;
        int win;
        for(int i = 1; i <= 52; ++i){
            if(vis[i]) continue;
            int arr[3] = {x, y, i};
            int o[3] = {0, 1, 2};
            bool stop = 0;
            do{
                win = 0;
                if(arr[o[0]] > a) win++;
                if(arr[o[1]] > b) win++;
                if(arr[o[2]] > c) win++;
                if(win < 2){
                    stop = 1; break;
                }
            }while(next_permutation(o, o+3));
            if(!stop){
                ok = 1;
                cout << i << endl;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
    }
    return 0;
}
/*
28 51 29 50 52
50 26 19 10 27
10 20 30 24 26
46 48 49 47 50
19 27 23 18 52
11 17 4 16 39
0 0 0 0 0
*/
