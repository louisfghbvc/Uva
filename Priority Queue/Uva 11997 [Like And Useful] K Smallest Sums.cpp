// O(K^2logk), Speed up use PQ.
// if all to all k^3, merge can cut if greater than now big.
// trick.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int k;
    while(cin >> k){
        vector<int> pq(k, 0);
        for(int i = 0; i < k; ++i){
            cin >> pq[i];
        }
        sort(pq.begin(), pq.end());
        for(int i = 1; i < k; ++i){
            vector<int> arr(k, 0);
            for(int j = 0; j < k; ++j){
                cin >> arr[j];
            }
            sort(arr.begin(), arr.end());
            priority_queue<int> PQ;
            for(int j = 0; j < k; ++j){
                PQ.push(pq[j]+arr[0]);
            }
            for(int j = 0; j < k; ++j){
                for(int n = 1; n < k; ++n){
                    if(pq[j] + arr[n] < PQ.top()){
                        PQ.pop();
                        PQ.push(pq[j] + arr[n]);
                    }
                    else break;
                }
            }
            int j = k-1;
            while(!PQ.empty())
                pq[j--] = PQ.top(), PQ.pop();
        }
        bool f = 1;
        for(const auto &v : pq){
            if(!f) cout << " ";
            cout << v;
            f = 0;
        }
        cout << endl;
    }
    return 0;
}
/**
3
1 8 5
9 2 5
10 7 6
2
1 1
1 2
**/
