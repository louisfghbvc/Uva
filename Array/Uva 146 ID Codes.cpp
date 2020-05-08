// Just permutation.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s), s != "#"){
        bool ok = 0;
        if(next_permutation(s.begin(), s.end())){
            ok = 1;
        }
        if(ok) cout << s << endl;
        else puts("No Successor");
    }
}
