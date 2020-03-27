#include <bits/stdc++.h>
#define N 32000
using namespace std;
typedef long long LL;

LL produceP(int n){
    return (LL)n * n + n + 41;    
}

bool np[N];
vector<int> p;
int pre[N];
bool isP(LL x){
    if(x < N)
        return !np[x];
    for(int i = 0; i < p.size(); ++i){
        if(x % p[i] == 0) return false;    
    }
    return true;
}

void init(){
    for(int i = 2; i < N; i++){
        if(!np[i]){
            p.push_back(i);
            for(int j = i*2; j < N; j+=i)
                np[j] = 1;
        }    
    }
}

int main()
{
    int a, b;
    init();
    memset(pre, 0, sizeof pre);
    pre[0] = 1;
    for(int i = 1; i < 10001; ++i)
        pre[i] = pre[i-1] + isP(produceP(i));
    while(cin >> a >> b){
        printf("%.02lf\n", (double)(pre[b] - pre[a - 1])/(b-a+1) * 100.0 + 1e-6);
    }
}
