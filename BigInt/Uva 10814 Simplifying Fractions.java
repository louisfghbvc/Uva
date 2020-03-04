package pkg10814;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fr = new FileReader("10814.in");
        Scanner input = new Scanner(fr);
        int t = input.nextInt();
        while(t-- > 0){
            BigInteger p = input.nextBigInteger();
            input.next();
            BigInteger q = input.nextBigInteger();
            BigInteger gcd = p.gcd(q);
            System.out.println(p.divide(gcd) + " / " +  q.divide(gcd));
            
        }
        fr.close();
    }
    
}
