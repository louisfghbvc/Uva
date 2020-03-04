//math is hard. euler function 
#include <bits/stdc++.h>
#define N 50005
using namespace std;
int phi[N];

void init(){
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

int main()
{
    int n;
    init();
    while(cin >> n, n){
        int ans = 0;
        for(int i = 2; i <= n; ++i){
            ans += phi[i];
        }
        cout << ans * 2 + 1 << endl;
    }
    return 0;
}
