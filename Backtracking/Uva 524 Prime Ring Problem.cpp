// use bitmask. just enum all case.


#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cy;
bool np[100];

void init(){
    for(int i = 2; i < 100; ++i){
        if(!np[i]){
            for(int j = 2*i; j < 100; j+=i)
                np[j] = 1;
        }
    }
}

void dfs(int d, int used){
    if(d == n){
        if(np[cy[d-1] + 1]) return;
        cout << 1;
        for(int i = 1; i < n; ++i)
            cout << " " << cy[i];
        cout << endl;
        return;
    }
    for(int i = 2; i <= n; ++i){
        if(used & (1<<i)) continue;
        if(np[i + cy[d-1]]) continue;
        cy.push_back(i);
        dfs(d+1, used | (1<<i));
        cy.pop_back();
    }
}

int main(){
    init();
    int cas = 1;
    while(cin >> n){
        if(cas != 1) puts("");
        printf("Case %d:\n", cas++);
        cy.clear();
        cy.push_back(1);
        dfs(1, 1);
    }
    return 0;
}
