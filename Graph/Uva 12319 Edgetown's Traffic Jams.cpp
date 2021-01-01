// All pair shortest path. and careful enum.

#include <bits/stdc++.h>
using namespace std;

int g1[105][105];
int g2[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n, n){
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                g1[i][j] = g2[i][j] = 1e5;

        cin.ignore();

        string str;
        for(int i = 1; i <= n; ++i){
            getline(cin, str);
            stringstream ss(str);
            ss >> i;
            int v;
            while(ss >> v){
                g1[i][v] = 1;
            }
        }

        for(int i = 1; i <= n; ++i){
            getline(cin, str);
            stringstream ss(str);
            ss >> i;
            int v;
            while(ss >> v){
                g2[i][v] = 1;
            }
        }

        int a, b;
        cin >> a >> b;

        for(int k = 1; k <= n; ++k){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
                    g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
                }
            }
        }

        bool g = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j) continue;
                if(g2[i][j] > g1[i][j] * a + b) g = 1;
            }
        }

        cout << (g ? "No" : "Yes") << "\n";
    }
}
