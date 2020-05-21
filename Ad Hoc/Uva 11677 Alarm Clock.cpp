// Just time, like circle.

#include <bits/stdc++.h>
using namespace std;
int main(){
    int h1, m1, h2, m2;
    while(cin >> h1 >> m1 >> h2 >> m2, h1+m1+h2+m2){
    	if(h1 > h2 || (h1==h2 && m1 > m2))
    		cout << 1440 - ((h1*60+m1) - (h2*60+m2)) << endl;
    	else
    		cout <<((h2*60+m2) - (h1*60+m1)) <<endl;
    
    }
    return 0;
}
