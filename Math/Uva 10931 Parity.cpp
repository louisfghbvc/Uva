//x > 0
#include <bits/stdc++.h>
using namespace std;

void print(int x){
  if(!x) return;
  print(x/2);
  cout << (x&1);
}

int main(){
    int i;
    while(cin >> i, i){
    	printf("The parity of ");
    	print(i);
    	printf(" is %d (mod 2).\n", __builtin_popcount(i));
    }
    return 0;
}
