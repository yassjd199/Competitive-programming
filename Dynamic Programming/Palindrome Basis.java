/*
 * Author: yassjd199
 * https://codeforces.com/contest/1673/problem/C
 */

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.Math.floor;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import static java.lang.Math.round;

import java.io.*;
import java.util.*;

/*
 * How many palandromic numbers x <=4*10^4 ? (brute forc it ) about 500 very goo?
 * 
 * now we can basically use dyinamic programming , 
 * 
 * and because order matters , (1 1 3 is the same as 3 1 1 ) then the state will be (i,curSum);
 * 
 * dp[i][curSum] = ans to the problem using the first i elements with curSum being what i made using first i elements
 * 
 * dp[i][curSum] = dp[i][curSum-A[i]]+dp[i-1][curSum] ;
 * 
 * dp[0][0] =1 (i can make 0 by not selecting any numbers );
 * 
 * 
 */
public class G {

    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);
    static ArrayList<Integer> A = new ArrayList<>();

    // static int dp[][] = new int[500][40010];
    static int dp[] = new int[40010];
    static int n;

    // static int S(int i, int curSum) {
    // if (curSum < 0)
    // return 0;
    // if (i >= A.size())
    // return curSum == 0 ? 1 : 0;

    // int ret = dp[i][curSum];
    // if (ret != -1)
    // return ret;
    // ret = 0;
    // ret += S(i, curSum - A.get(i)) % MOD;
    // ret += S(i + 1, curSum) % MOD;
    // ret %= MOD;
    // return dp[i][curSum] = ret;

    // }

    static void testcase() {

        n = in.nextInt();
        out.println(dp[n]);
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        int t = 1;
        t = in.nextInt();
        for (int i = 1; i <= 40000; i++) {
            String x = String.valueOf(i);
            String revx = new StringBuilder(x).reverse().toString();
            int revi = Integer.parseInt(revx);
            if (i == revi) {
                A.add(i);
            }
        }

        // for (int i = 0; i < 500; i++)
        // for (int j = 0; j <= 40000; j++)
        // dp[i][j] = -1;
        // // dbg(A.size());

        dp[0] = 1;
        for (int i = 0; i < A.size(); i++) {
            for (int curSum = A.get(i); curSum <= 40000; curSum++) {
                dp[curSum] += dp[curSum - A.get(i)] % MOD;
                dp[curSum] %= MOD;
            }
        }

        for (int tt = 1; tt <= t; tt++) {
            testcase();
        }
        out.flush();
        out.close();
        long end = System.currentTimeMillis();
        System.err.println("\nRun Time: " + (end - start) / 1000.0 + "s");
    }

    static void dbg(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return "";
        }
    }

    /*
     * /\_/\
     * (= ._.)
     * / > \>
     */
}
