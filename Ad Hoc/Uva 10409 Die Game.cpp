//just simulate. record 6 details.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int c;
    while(scanf("%d\n", &c) != EOF && c){
    	string s;
    	int die[7] = {0, 1, 2, 3, 4, 5, 6};
    	for(int i = 0; i < c; ++i){
    		cin >> s;
    		if(s == "north"){
    			int v = die[2];
    			die[2] = die[1];
    			die[1] = die[5];
    			die[5] = die[6];
    			die[6] = v;
    		}
    		else if(s == "south"){
    			int v = die[6];
    			die[6] = die[5];
    			die[5] = die[1];
    			die[1] = die[2];
    			die[2] = v;
    		}
    		else if(s == "east"){
    			int v = die[6];
    			die[6] = die[4];
    			die[4] = die[1];
    			die[1] = die[3];
    			die[3] = v; 
    		}
    		else if(s == "west"){
    			int v = die[6];
    			die[6] = die[3];
    			die[3] = die[1];
    			die[1] = die[4];
    			die[4] = v; 
    		}
    	}
		cout << die[1] << endl;    	
    }
    return 0;
}
/*
  2
3 1 4  
  5
  6
*/
