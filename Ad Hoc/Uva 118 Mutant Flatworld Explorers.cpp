#include <bits/stdc++.h>
using namespace std;

char dir;
int n, m, x, y;

char rot(char cmd){
	if(cmd == 'R'){
		if(dir == 'E') return 'S';
		if(dir == 'S') return 'W';
		if(dir == 'W') return 'N';
		if(dir == 'N') return 'E';
	}
	else{
		if(dir == 'E') return 'N';
		if(dir == 'N') return 'W';
		if(dir == 'W') return 'S';
		if(dir == 'S') return 'E';
	}
}

int main(){
    bool vis[55][55] = {};
    string s;
    cin >> n >> m;
    while(cin >> x >> y >> dir){
    	cin.ignore();
    	getline(cin, s);
    	bool flag = 0;
    	for(const char &c: s){
    		int nx = x, ny = y;
    		switch(c){
    			case 'L':
    			case 'R':
    				dir = rot(c);
    				break;
    			case 'F':
    				if(dir == 'E'){
    					nx++;
    				}
    				if(dir == 'W'){
    					nx--;
    				}
    				if(dir == 'S'){
    					ny--;
    				}
    				if(dir == 'N'){
    					ny++;
    				}
    				break;
    		}
    		if(nx < 0 || ny < 0 || nx > n || ny > m){
    			if(vis[x][y]) continue;
    			flag = 1, vis[x][y] = 1;
    			break;
    		}
    		x = nx, y = ny;
    	}
    	printf("%d %d %c", x, y, dir);
    	puts(flag ? " LOST" :"");
    }
    return 0;
}
/**
  N
W   E
  S
 12345
3  1 
2  1
1  
0
**/
