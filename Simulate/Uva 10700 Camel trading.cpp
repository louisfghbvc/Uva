// Max is add, min is mul
// Simulate. Can be optimal to one pass.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        LL mx = 1, mn = 0;
        stack<LL> addSt;
        stack<LL> mulSt;
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                LL t = 0;
                while(i < s.size() && isdigit(s[i])){
                    t = t*10 + s[i]-'0';
                    i++;
                }
                addSt.push(t);
                i--;
            }
            if(s[i] == '+'){
                i++;
                LL t = 0;
                while(i < s.size() && isdigit(s[i])){
                    t = t*10 + s[i]-'0';
                    i++;
                }
                i--;
                LL tmp = addSt.top() + t; addSt.pop();
                addSt.push(tmp);
            }
        }
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                int t = 0;
                while(i < s.size() && isdigit(s[i])){
                    t = t*10 + s[i++]-'0';
                }
                mulSt.push(t);
                i--;
            }
            else if(s[i] == '*'){
                i++;
                int t = 0;
                while(i < s.size() && isdigit(s[i])){
                    t = t*10 + s[i++]-'0';
                }
                i--;
                LL tmp = mulSt.top()*t; mulSt.pop();
                mulSt.push(tmp);
            }
        }
        while(!addSt.empty()){
            mx *= addSt.top(); addSt.pop();
        }
        while(!mulSt.empty()){
            mn += mulSt.top(); mulSt.pop();
        }
        printf("The maximum and minimum are %lld and %lld.\n", mx, mn);
    }
    return 0;
}
