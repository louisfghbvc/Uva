import java.util.*;
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
