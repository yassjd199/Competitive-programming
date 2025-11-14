/*
 * Author: yassjd199
 * https://codeforces.com/contest/2144/problem/C
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

public class Main {

    static final int N = 1000006;
    static final int MOD = 998244353;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void testcase() {
        int n = in.nextInt();
        int A[] = in.readArray(n);
        int B[] = in.readArray(n);

        long dp[][] = new long[n][2];
        dp[0][1] = dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            // keep them in place;
            if (A[i] >= A[i - 1] && B[i] >= B[i - 1]) {
                dp[i][0] += dp[i - 1][0];
                dp[i][0] %= MOD;
            }
            if (A[i] >= B[i - 1] && B[i] >= A[i - 1]) {
                dp[i][0] += dp[i - 1][1];
                dp[i][0] %= MOD;
            }

            // swap;

            if (B[i] >= A[i - 1] && A[i] >= B[i - 1]) {
                dp[i][1] += dp[i - 1][0];
                dp[i][1] %= MOD;
            }
            if (B[i] >= B[i - 1] && A[i] >= A[i - 1]) {
                dp[i][1] += dp[i - 1][1];
                dp[i][1] %= MOD;
            }

        }
        out.println((dp[n - 1][0] + dp[n - 1][1]) % MOD);
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        int t = 1;
        t = in.nextInt();
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
