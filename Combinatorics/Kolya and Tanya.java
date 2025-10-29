/*
 * Author: yassjd199
 * https://codeforces.com/contest/584/problem/B
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
 * 
 * 
 * what i found is that the answer is 3^(3*n) - SUM(nCi*(6^i)) i form 0 to n 
 * but i turns out that the sum is actually equal to 7^n  (editorial);
 */

public class Main {

    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static long exp(long a, long b) {
        // a %= MOD;
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

    static long C(int n, int k) {
        return (F[n] * inv((F[k] * F[n - k]) % MOD)) % MOD;

    }

    static long F[] = new long[N];

    static void testcase() {
        int n = in.nextInt();
        // long tot = exp(27, n);
        // long bad = 0L;
        // for (int i = 0; i <= n; i++) {
        // bad += (C(n, i) * exp(6, i)) % MOD;
        // bad %= MOD;
        // }
        // out.println((tot - bad + MOD) % MOD);

        // bad ones are the ones with no ai + a+n +ai+2*n!=6 so any {1,2,3} permutation
        // we have 6 of those
        // or {2,2,2} so in total 7
        // we have n spots each one could have 7 possible vaules so that
        // a total of 7^n bad ones.
        // and the total posssible combinations is 3^(3*n) = 27^n
        // so the final answer is 27^n - 7^n
        long tot = 1L;
        long bad = 1L;
        for (int i = 0; i < n; i++) {
            tot = (tot * 27) % MOD;
            bad = (bad * 7) % MOD;
        }
        out.println((tot - bad + MOD) % MOD);
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        int t = 1;
        // t = in.nextInt();
        F[0] = F[1] = 1L;
        for (int i = 2; i <= 100000; i++) {
            F[i] = (i * 1L % MOD) * (F[i - 1]);
            F[i] %= MOD;
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
