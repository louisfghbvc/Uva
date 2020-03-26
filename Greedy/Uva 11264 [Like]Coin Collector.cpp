#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n + 2];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int cnt = 0, sum = 0;
        for(int i = 0; i < n - 1; ++i){
            if(sum + arr[i] < arr[i + 1]){
                sum += arr[i];
                cnt++;
            }
        }

        cout << cnt+1 << endl;
    }
    return 0;
}
