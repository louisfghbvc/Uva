// Just Simulate all node O(N^3)
// Floyd Warshall
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int a, b, cas = 1;
    int w[105][105];
    while(cin >> a >> b, a+b){
        memset(w, 0x3f, sizeof w);
        w[a][b] = 1;
        while(cin >> a >> b, a+b){
            w[a][b] = 1;
        }
        for(int k = 1; k <= 100; k++){
            for(int i = 1; i <= 100; ++i){
                for(int j = 1; j <= 100; ++j){
                    w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
                }
            }
        }
        int cnt = 0, sum = 0;
        for(int i = 1; i <= 100; ++i){
            for(int j = 1; j <= 100; ++j){
                if(w[i][j] != INF && i != j){
                    sum += w[i][j];
                    cnt++;
                }
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n", cas++, (double)sum/cnt);
    }
    return 0;
}
/**
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0
**/
