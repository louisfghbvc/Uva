//O(nloglogn), Euler is amazing. delete 2's, 3's, 5's ...
#include <bits/stdc++.h>
#define N 2000005
using namespace std;

int phi[N];

void phi_init(){
    memset(phi, 0, sizeof phi);
    phi[1] = 1; 
    for(int i = 2; i < N; ++i){
        if(!phi[i]){
            for(int j = i; j < N; j += i){
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }   
    }
}

int dep_phi(int x){
    int cnt = 0;
    while(x != 1){
        x = phi[x];
        cnt++;
    }
    return cnt;
}

int main()
{
    phi_init();
    
    int t, m, n;
    cin >> t;
    while(t--){
        cin >> m >> n;
        
        int res = 0;
        for(int i = m; i <= n; ++i){
            res += dep_phi(i);
        }
        
        cout << res << endl;
    }
    return 0;
}
