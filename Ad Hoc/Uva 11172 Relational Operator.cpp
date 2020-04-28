#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a < b)
            puts("<");
        else if(a > b)
            puts(">");
        else
            puts("=");
    }
    return 0;
}
