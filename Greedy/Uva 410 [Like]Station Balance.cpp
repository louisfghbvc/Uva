//Cool solve. balance max to small, put in order. 
#include <bits/stdc++.h>

using namespace std;
vector<int> cc[12];
int main()
{
    int c, s, cas = 1;
    while(cin >> c >> s){
        int arr[s + 2], sum = 0;
        double avg, imb = 0.0;
        for(int i = 0; i < c; ++i) cc[i].clear();
        for(int i = 0; i < s; ++i){
            cin >> arr[i];
            sum += arr[i];
        }
        avg = (double)sum/c;
        sort(arr, arr+s, greater<int>());

        int i, j;
        for(i = 0, j = 0; i < s && j < c; ++i, ++j){
            cc[j].push_back(arr[i]);
        }
        j--;
        for(; i < s && j >= 0; ++i, --j){
            cc[j].push_back(arr[i]);
        }

        printf("Set #%d\n", cas++);
        for(int i = 0; i < c; ++i){
            printf(" %d:", i);
            double ts = 0.0;
            for(int j = 0; j < cc[i].size(); ++j){
                printf(" %d", cc[i][j]);
                ts += cc[i][j];
            }
            imb += abs(ts - avg);
            puts("");
        }

        printf("IMBALANCE = %.5f\n\n", imb);
    }
    return 0;
}
