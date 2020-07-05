#include <bits/stdc++.h>
#define MAX_BOLTS 500
#define MAX_NUTS 500
using namespace std;

int nuts, bolts;
int fits[MAX_BOLTS][MAX_NUTS];
int nut_used[MAX_NUTS], match_n[MAX_NUTS];
int bestmatched;

void read_input_data(){
    cin >> bolts >> nuts;
    for(int i = 0; i < bolts; ++i)
        for(int j = 0; j < nuts; ++j)
            cin >> fits[i][j];
}

void init_match(){
    bestmatched = 0;
    memset(match_n, -1, sizeof match_n);
}

bool dfs(int b){
    for(int n = 0; n < nuts; ++n) if(fits[b][n] && !nut_used[n]){
        nut_used[n] = 1;
        if(match_n[n] == -1 || dfs(match_n[n])){
            match_n[n] = b;
            return true;
        }
    }
    return false;
}

void match_bolt(){
    for(int b = 0; b < bolts; ++b){
        memset(nut_used, 0, sizeof nut_used);
        if(dfs(b)) bestmatched++;
    }
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int cases, caseno = 1;
    cin >> cases;
    while(cases--){
        read_input_data();
        init_match();
        match_bolt();

        printf("Case %d: ", caseno++);
        printf("a maximum of %d nuts and bolts ", bestmatched);
        printf("can be fitted together\n");
    }
}
/**
2
3 4
0 0 1 0
1 1 0 1
0 0 1 0
5 5
1 0 0 1 1
1 1 0 0 0
1 0 0 0 0
0 1 1 0 0
0 0 0 0 1
**/
