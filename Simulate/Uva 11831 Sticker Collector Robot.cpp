// 4 direction, simulate robot walk.
#include <bits/stdc++.h>
using namespace std;

int dir;
int walk[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int setdir(char c){
    if(c == 'N') return 0;
    if(c == 'L') return 1;
    if(c == 'S') return 2;
    return 3;
}
void turn(char c){
    if(c == 'D') dir++;
    if(c == 'E') dir--;
    dir = (dir+4)%4;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int n, m, s;
    char g[105][105];
    while(cin >> n >> m >> s, n+m+s){
        int x = 0, y = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> g[i][j];
                if(g[i][j] != '.' && g[i][j] != '*' && g[i][j] != '#')
                    x = i, y = j, dir = setdir(g[i][j]), g[i][j] = '.';
            }
        }
        int ans = 0;
        char c;
        int ny, nx;
        for(int i = 0; i < s ; ++i){
            cin >> c;
            if(c == 'F'){
                nx = x+walk[dir][0], ny = y+walk[dir][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#') continue;
                if(g[nx][ny] == '*'){
                    ans++;
                    g[nx][ny] = '.';
                }
                x = nx, y = ny;
            }
            else{
                turn(c);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/**
3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF
0 0 0
**/
