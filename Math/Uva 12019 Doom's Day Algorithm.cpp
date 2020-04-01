#include <bits/stdc++.h>
using namespace std;
int main(){
   	int t, m, d;
   	cin >> t;
   	string day[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
   	int dates[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   	for(int i = 1; i <= 12; ++i)
   		dates[i] += dates[i-1];
   	while(t--){
   		cin >> m >> d;
   		int it = 4;
   		cout << day[(it+dates[m-1]+d)%7] << endl;
   	}
    return 0;
}
