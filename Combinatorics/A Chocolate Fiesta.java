import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
/*

    Author: yassjd199
    https://www.hackerrank.com/challenges/a-chocolate-fiesta/problem

*/
class Result {
    
        static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

        static final int MOD = 1000000000 + 7;
        static final int N = 100006;

        static long exp(long a, long b) {
        long ret = 1L;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret *= a;
                ret %= MOD;
            }
            a *= a;
            a %= MOD;
            b >>= 1;
        }
        return ret;
    }

    static long inv(long a) {
        return exp(a, MOD - 2);
    }


    public static int solve(List<Integer> a) {
    // Write your code here

        int n = a.size();
        long e=0;
        
        
        long ansO=0;
        for(int i=0;i<n;i++){
            if(a.get(i)%2==0) e++;
        }
        long ans = exp(2,e);
        ans*=exp(2,Math.max(0,n-e-1));
        ans%=MOD; 
        ans=ans-1+MOD;
        ans%=MOD;
        
       
        return (int)ans ;
    }
    
    

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int aCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> a = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.solve(a);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
