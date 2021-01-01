// Find divisor, and build table. query O(1).

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
vector<int> prime;
bool np[N];
int table[N];

void init(){
    for(int i = 2; i <= sqrt(N); ++i){
        if(!np[i]){
            prime.push_back(i);
            for(int j = i+i; j < N; j+=i) np[j] = 1;
        }
    }

    int mx = 1, mxi = 1;
    for(int i = 1; i <= 1e6; ++i){
        int x = i;
        int fac = 1;
        for(int &p: prime){
            if(p > x) break;
            int c = 1;
            while(x % p == 0){
                x /= p;
                c++;
            }
            fac *= c;
        }
        if(x != 1) fac *= 2;
        if(mx <= fac){
            mx = fac;
            mxi = i;
        }
        table[i] = mxi;
    }
}

void solve(){
    int n;
    cin >> n;
    cout << table[n] << "\n";
}

int main() {
    init();
    int t;
    cin >> t;
    while(t--) solve();
}
