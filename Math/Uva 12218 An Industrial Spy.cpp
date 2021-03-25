// Build prime table. O(NlogN).
// Brute Force all candidate and permutation O(2^N N!)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

bool np[N];
void init(){
    for(int i = 2; i <= sqrt(N); ++i){
        for(int j = 2*i; j < N; j += i)
            np[j] = 1;
    }
}

int main() {
    //cin.tie(0); ios::sync_with_stdio(false);
    init();
    int T;
    cin >> T;
    np[1] = np[0] = 1;
    for(int t = 0; t < T; ++t){
        string s;
        cin >> s;
        sort(s.begin(), s.end());

        set<int> res;
        for(int i = 1; i < 1<<s.size(); ++i){

            string tmp = "";
            for(int j = 0; j < (int)s.size(); ++j){
                if(i>>j&1) tmp += s[j];
            }

            do{
                int num = stoi(tmp);
                if(np[num] || res.count(num)) continue;
                res.insert(num);
            }while(next_permutation(tmp.begin(), tmp.end()));

        }

        cout << res.size() << "\n";
    }
}
/**
4
17
1276543
9999999
011
**/
