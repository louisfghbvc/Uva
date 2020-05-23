// O(N!). Enum all case, record minimum.
// can use dp. but n is small.

#include <bits/stdc++.h>
using namespace std;

int o[10], x[10], y[10], ans[10];
int main()
{
    //freopen("out.txt", "w", stdout);
    int n, cas = 1;
    while(cin >> n, n){
        for(int i = 0; i < n; ++i)
            cin >> x[i] >> y[i], o[i] = i;

        double mn = 1e9;
        do{
            double sum = 0;
            for(int i = 1; i < n; ++i){
                sum += (sqrt(pow(x[o[i]]-x[o[i-1]],2.0)+pow(y[o[i]]-y[o[i-1]],2.0))+16.0);
            }
            if(sum < mn) memcpy(ans, o, sizeof o), mn = sum;
        }while(next_permutation(o, o+n));

        puts("**********************************************************");
        printf("Network #%d\n", cas++);
        for(int i = 1; i < n; ++i){
            double dis = sqrt(pow(x[ans[i]]-x[ans[i-1]],2.0)+pow(y[ans[i]]-y[ans[i-1]],2.0))+16.0;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", x[ans[i-1]], y[ans[i-1]],
                   x[ans[i]], y[ans[i]], dis);
        }
        printf("Number of feet of cable required is %.2f.\n", mn);
    }
    return 0;
}
/**
6
5 19
55 28
38 101
28 62
111 84
43 116
5
11 27
84 99
142 81
88 30
95 38
3
132 73
49 86
72 111
0
**/
