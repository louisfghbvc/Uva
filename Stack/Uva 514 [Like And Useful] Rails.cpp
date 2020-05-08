// trick. 3 case
// now is same as array. now++
// now is bigger, check stack if exist.
// now is smaller, now++ until = array.

#include <bits/stdc++.h>
#define N 1005
using namespace std;

int arr[N];
int main()
{
    int n;
    while(cin >> n, n){
        while(cin >> arr[0], arr[0]){
            for(int i = 1; i < n; ++i) cin >> arr[i];
            stack<int> st;
            int now = 1;
            bool ok = 1;
            for(int i = 0; i < n; ++i){
                if(now == arr[i]) now++;
                else if(now < arr[i]){
                    while(now < arr[i]){
                        st.push(now++);
                    }
                    now++;
                }
                else{
                    if(!st.empty() && st.top() == arr[i]) st.pop();
                    else ok = 0;
                }
            }
            puts(ok ? "Yes" : "No");
        }
        puts("");
    }
}
