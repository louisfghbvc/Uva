#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

// numbers of different so far
LL cal(LL x){
    return x / 5;
}

int main() {
    LL l, r;
    while(cin >> l >> r, l+r){
        cout << cal(r) - cal(l) + 1 << "\n";
    }

}
