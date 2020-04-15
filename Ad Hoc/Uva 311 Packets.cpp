//Case think
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[6];
    while(1){
        int allzero = 0;
        for(int i = 0; i < 6; ++i){
            cin >> arr[i];
            allzero += arr[i];
        }
        if(!allzero) break;
        int box = arr[5]+arr[4]+arr[3];

        arr[0] -= 11*arr[4]; // one 5x5, eleven 1x1
        arr[1] -= 5*arr[3];  // one 4x4, five 2x2

        box += (arr[2]/4); if(arr[2]%4) box++;

        if(arr[2]%4){
            arr[1] = arr[1] - (8-(arr[2]%4*2+1));
            arr[0] = arr[0] - (8-arr[2]%4);
        }

        if(arr[1] > 0){ // 2x2
            box += arr[1]/9;
            if(arr[1]%9){
                box++;
                arr[0] -= (36-(arr[1]%9)*4);
            }
        }
        else if(arr[1] < 0){ // 4 1x1
            arr[0] = arr[0] + 4*arr[1];
        }

        if(arr[0] > 0){
            box += arr[0]/36;
            if(arr[0]%36) box++;
        }

        cout << box << endl;
    }
    return 0;
}
/*
0 0 4 0 0 1
7 5 1 0 0 0
11 12 13 14 15 16
10 10 10 10 10 10
5000 1400 300 200 100 100
0 0 0 0 0 0
*/
