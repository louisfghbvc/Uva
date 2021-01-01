// ad-hoc, just simulate.

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int e, f, c;
    cin >> e >> f >> c;

    int res = 0;
    e += f;
    while(e >= c){
        res += e/c;
        e = e/c + e%c;
    }
    cout << res << "\n";
}

int main() {
    int n;
    cin >> n;
    while(n--) solve();
}
