//Mod Rule. O(N)
#include <bits/stdc++.h>
#define NP 131071
using namespace std;

int main()
{
    string s, s2 = "";
    while(getline(cin , s)){
        s2 += s;
        if(s.back() == '#'){
            int jud = 0;
            for(int i = 0; i < s2.size() - 1; ++i){
                jud = (jud * 2 + (s2[i] - '0')) % NP;
            }
            if(jud == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
            s2 = "";
        }
    }
}
