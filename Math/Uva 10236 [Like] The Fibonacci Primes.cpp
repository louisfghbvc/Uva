// Special fib prime.
// use double to round. when have carry flag. f[i-2] must /10 
// so that digit are equal. 

#include <bits/stdc++.h>
#define N 250005
using namespace std;
typedef long long LL;

bool np[N];
vector<int> prime;
double fb[N];
void init(){
    for(int i = 2; i < N; ++i){
        if(!np[i]){
            prime.push_back(i);
            for(int j = 2*i; j < N; j+=i){
                if(j == 4)continue;
                np[j] = 1;
            }
        }
    }
    fb[0] = 0;
    fb[1] = 1;
    int flag = 0;
    for(int i = 2; i < N; ++i){
        fb[i] = fb[i-1]+ (flag ? fb[i-2]/10 : fb[i-2]);
        flag = 0;
        if(fb[i] >= 1e9){
            flag = 1;
            fb[i] /= 10;
        }
    }
}

int main()
{
    int n;
    init();
    while(cin >> n){
        cout << (int)fb[prime[n]] << endl;
    }
    return 0;
}
