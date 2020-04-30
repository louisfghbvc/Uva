// Simulate. each month
// care one months...
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int month, num, m;
    double down, loan;
    while(cin >> month >> down >> loan >> num){
        if(month < 0) break;
        double rate[105] = {};
        for(int i = 0; i < num; ++i){
            cin >> m;
            cin >> rate[m];
            // cout << rate[m] << endl;
        }
        double car = down+loan, money = loan/month;
        double now_rate = 0.0;
        for(int i = 0; i <= month; ++i){
            if(rate[i] > 0.0) now_rate = rate[i];
            car *= (1.0-now_rate);
            // printf("rate: %lf car: %lf loan: %lf\n", 1.0-now_rate, car, loan);
            if(loan < car){
                // printf("%lf %lf\n", loan, car);
                if(i != 1)
                    printf("%d months\n", i);
                else
                    printf("%d month\n", i);
                break;
            }
            loan -= money;
        }
    }
}
/*
30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500.0 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
-99 0 17000 1
*/
