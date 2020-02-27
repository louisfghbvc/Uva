#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    string str;
    while(cin >> n, n){
        vector<vector<int>> d(n + 1, vector<int>(n + 1, 1e7));
        cin.ignore();
        while(getline(cin, str)){
            if(str == "0") break;
            stringstream ss(str);
            int be, nt;
            ss >> be;
            while(ss >> nt, nt)
                d[be][nt] = 1;
        }
        for(int k = 1; k <= n; ++k){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    if(d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
        cin >> m;
        for(int i = 0; i < m; ++i){
            int st;
            vector<int> arr;
            cin >> st;
            for(int k = 1; k <= n; ++k){
                if(d[st][k] == 1e7){
                    arr.push_back(k);
                }
            }
            cout << arr.size();
            for(int k : arr){
                cout << " " << k;
            }
            cout << endl;
        }

    }
    return 0;
}
