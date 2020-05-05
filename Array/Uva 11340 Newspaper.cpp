// Use Stl map or a array. Simple add
// watch out %02d
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("11340.txt", "r", stdin);
    int n, k;
    string s;
    cin >> n;
    while(n--){
        cin >> k;
        map<char, int> mp;
        for(int i = 0; i < k; ++i){
            char c; int v;
            cin >> c >> v;
            mp[c] = v;
        }
        cin >> k;
        cin.ignore();
        int tot = 0;
        for(int i = 0; i < k; ++i){
            getline(cin, s);
            for(const auto& c: s){
                tot += mp[c];
            }
        }
        printf("%d.%02d$\n", tot/100, tot%100);
    }
    return 0;
}
