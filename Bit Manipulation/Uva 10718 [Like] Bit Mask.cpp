// O(1)
// Maintain ans in range. let max be all one.
// Trick
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    LL n, L, U;
    while(cin >> n >> L >> U){
        LL m = 0;
        for(int i = 32; i >= 0; --i){
            LL cur = (1LL<<i);
            if(n & cur){
                if(m+cur-1 < L){
                    m |= cur;
                }
            }else{
                if(m+cur <= U){
                    m |= cur;
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}
