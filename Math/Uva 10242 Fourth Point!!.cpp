//make b, c same.
#include <bits/stdc++.h>
using namespace std;
struct point{
	double x, y;
}p[4];
int main(){
   	
   	while(cin >> p[0].x >> p[0].y){
   		for(int i = 1; i < 4; ++i)
   			cin >> p[i].x >> p[i].y;
   		if(p[0].x == p[2].x && p[0].y == p[2].y)
   			swap(p[0], p[1]);
   		else if(p[3].x == p[1].x && p[3].y == p[1].y)
   			swap(p[2], p[3]);
   		if(p[0].x == p[3].x && p[0].y == p[3].y){
   			swap(p[0], p[1]); swap(p[2], p[3]);
   		}
   		if(p[0].x == p[3].x && p[0].y == p[3].y){
   			swap(p[0], p[1]); swap(p[2], p[3]);
   		}
   			
   		printf("%.3f %.3f\n", p[0].x+p[3].x-p[2].x, p[0].y+p[3].y-p[2].y);
   	}
    return 0;
}
//p2 + p4 = p1 + p3
