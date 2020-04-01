//cpe can't pass. but uva ac.
#include <bits/stdc++.h>
using namespace std;

int main(){
	string str[105] = {};
	int r = 0, c = 0;
    while(getline(cin, str[r])) c = max((int)str[r++].size(), c);
    for(int j = 0; j < c; ++j){
    	for(int i = r - 1; i >= 0; --i){
    		if(j >= str[i].size()) putchar(' ');
    		else cout << str[i][j];
    	}
    	cout << endl;
    }
    return 0;
}
/**
 sdljl gsl ls dlg
     sjldgj ldsj glsjd glsdlsa 
     glsd lg dslg sl gdsl 
     jdsl sdlkgjl 
**/
