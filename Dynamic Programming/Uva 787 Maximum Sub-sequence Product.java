// O(N). one pass.
// Concept from Leetcode.
// Maintain min, max. if num is neg, swap min max

import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int []arr = new int[105];
        int n;
        while(input.hasNext()){
            n = 0;
            while(input.hasNextInt()){
                arr[n] = input.nextInt();
                if(arr[n] == -999999) break;
                n++;
            }
            
            BigInteger res = BigInteger.valueOf(arr[0]);
            BigInteger imax = BigInteger.valueOf(arr[0]);
            BigInteger imin = BigInteger.valueOf(arr[0]);
            for(int i = 1; i < n; ++i){
                BigInteger num = BigInteger.valueOf(arr[i]);
                if(num.compareTo(BigInteger.ZERO) == -1){
                    BigInteger tmp = imax;
                    imax = imin;
                    imin = tmp;
                }
                imax = num.max(imax.multiply(num));
                imin = num.min(imin.multiply(num));
                res = res.max(imax);
            }
            System.out.println(res);
        }
    }
    
}
