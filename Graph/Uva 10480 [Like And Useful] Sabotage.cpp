//EK algorithm, min cut, record cut edge, Useful, impressive
#include <bits/stdc++.h>
#define N 55
#define INF 1e9
using namespace std;
int cap[N][N], f[N][N];
int af[N], pre[N];
int s, t, n, m;

void EK(){
    
    while(1){
        
        memset(pre, -1, sizeof pre);
        memset(af, 0, sizeof af);
        queue<int> q;
        q.push(s);
        af[s] = INF;
        
        while(!q.empty()){
            int u = q.front(); q.pop();
        
            for(int v = 1; v <= n; ++v){
                if(!af[v] && cap[u][v] > f[u][v]){
                    af[v] = min(af[u], cap[u][v] - f[u][v]);
                    pre[v] = u;
                    q.push(v);
                }
                
            }
        }
        
        if(!af[t]) break;
        
        for(int u = t; u != s; u = pre[u]){
            f[pre[u]][u] += af[t];
            f[u][pre[u]] -= af[t];
        }
        
    }
    
}

int main()
{
   while(cin >> n >> m, n + m){
       
       memset(cap, 0, sizeof cap);
       memset(f, 0, sizeof f);
       
       for(int i = 0; i < m; ++i){
           int a, b, c;
           cin >> a >> b >> c;
           cap[a][b] = cap[b][a] = c;
       }
       
       s =  1, t = 2;
       
       EK();
       
       for(int i = 1; i <= n; ++i){
           if(af[i] > 0){
               for(int j = 1; j <= n; ++j){
                   if(!af[j] && cap[i][j]){
                       cout << i << " " << j << "\n";
                   }
               }
           }
           
       }
       cout << endl;
       
   }
   
   return 0;
}
