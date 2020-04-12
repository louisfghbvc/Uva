/*import java.util.*;
import java.math.BigInteger;
public class Main{
    public static void main(String[] args) {
        int n;
        Scanner in = new Scanner(System.in);
        while(in.hasNextInt()){
        	n = in.nextInt();
        	if(n < 2){
        		System.out.printf("The Fibonacci number for %d is %d\n", n, n);
        		continue;
        	}
        	BigInteger f0 = BigInteger.ZERO;
        	BigInteger f1 = BigInteger.ONE;
        	BigInteger ans = new BigInteger("0");
        	for(int i = 2; i <= n; ++i){
        		ans = f0.add(f1);
        		f0 = f1;
        		f1 = ans;
        	}
        	System.out.printf("The Fibonacci number for %d is %s\n", n, String.valueOf(ans));
        }
        
    }
};
*/
//C++ BigInt
#include <bits/stdc++.h>
#define N 305
using namespace std;

int dp[5001][N];

int main(){
	dp[1][0] = 1;
	for(int i = 2; i <= 5000; ++i){
		for(int j = 0; j < N; ++j)
			dp[i][j] = dp[i-1][j]+dp[i-2][j];
		for(int j = 0; j < N; ++j){
			dp[i][j+1] += dp[i][j]/10000;
			dp[i][j] %= 10000;
		}
	}
    int n;
    while(scanf("%d", &n) != EOF){
    	int i;
    	for(i = N-1; i >= 0 && !dp[n][i]; --i);
    	printf("The Fibonacci number for %d is ", n);
    	printf("%d", dp[n][i--]);
    	for(; i >= 0; --i)
    		printf("%04d", dp[n][i]);
    	puts("");
    }
    return 0;
}
