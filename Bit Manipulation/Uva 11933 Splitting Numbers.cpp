//Just from small to big. and change dir
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n, n){
        int a = 0, b = 0;
        bool dir = 0;
        for(int i = 0; i <= 30; ++i){
            if(n & (1<<i)){
                if(!dir) a|= (1<<i);
                else b|= (1<<i);
                dir ^= 1;
            }
        }
        cout << a << " " << b << endl;
    }
}
