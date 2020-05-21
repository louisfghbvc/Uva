// O(26^3 * log(N)).
// timelimit.
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >>t;
    string s;
    while(t--){
    	cin >> s;
    	vector<int> pos[26];
    	for(int i = 0; i < s.size(); ++i){
    		pos[s[i]-'A'].push_back(i);
    	}
    	int res = 0;
    	for(char a = 'A'; a <= 'Z'; ++a){
    		for(char b = 'A'; b <= 'Z'; ++b){
    			for(char c = 'A'; c <= 'Z'; ++c){
    				char t[3] = {a, b, c};
    				int j = 0;
    				int x = -1;
    				for(; j < 3; ++j){
    					int v = t[j] - 'A';
    					auto it = upper_bound(pos[v].begin(), pos[v].end(), x);
    					if(it != pos[v].end()) x = *it;
    					else break;
    				}
    				if(j == 3) res++;
    			}
    		}	
    	}
    	cout << res << endl;
    }
    return 0;
}

// very fast solve. O(26^3)
// the idea is from back to begin.
// record the appear char
// use memcpy very simple. memcpy(dist, source, len)

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXC = 26;
char s[MAXN];
int pos[MAXN][MAXC];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = (int) strlen(s);
        for (int i = 0; i < MAXC; i++)
            pos[n][i] = n;
        for (int i = n-1; i >= 0; i--) {
            memcpy(pos[i], pos[i+1], sizeof(pos[0]));
            int x = s[i]-'A';
            pos[i][x] = i;
        }
        
        int ret = 0;
        for (int a = 0; a < 26; a++) {
            if (pos[0][a] == n) continue;
            int x = pos[0][a];
            for (int b = 0; b < 26; b++) {
                if (pos[x+1][b] == n) continue;
                int y = pos[x+1][b];
                for (int c = 0; c < 26; c++) {
                    if (pos[y+1][c] == n) continue;
                    ret++;
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
