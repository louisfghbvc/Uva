//Care '\n'
#include <bits/stdc++.h>
using namespace std;

string judge(string &a, string &b){
    if(a == b)
        return "Accepted";
    string ac = "", bc = "";
    for(auto &s: a)
        if(isdigit(s)) ac += s;
    for(auto &s: b)
        if(isdigit(s)) bc += s;
    if(ac == bc)
        return "Presentation Error";
    return "Wrong Answer";
}

int main()
{
    int n, m, cas = 1;
    while(cin >> n, n){
        cin.ignore();
        string s1 = "", tmp, s2 = "";
        for(int i = 0; i < n; ++i)
            getline(cin, tmp), s1 += tmp+"\n";
        cin >> m;
        cin.ignore();
        for(int i = 0; i < m; ++i)
            getline(cin, tmp), s2 += tmp+"\n";
        printf("Run #%d: %s\n", cas++, judge(s1, s2).c_str());
    }
}
