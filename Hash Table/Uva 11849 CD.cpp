// Set use.
// Check if exist, cnt++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x;
    while(cin >> n >> m, n+m){
        unordered_set<int> st;
        for(int i = 0; i < n; ++i){
            cin >> x; st.insert(x);
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            cin >> x;
            if(st.count(x)) cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}
