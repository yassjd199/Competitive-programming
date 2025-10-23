/*
 * Author: yassjd199
 * https://codeforces.com/contest/1731/problem/C
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
    static final int MOD = 1000000000 + 7;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    /*
     * 1 - A number have an odd number of divisors if and only if it is a perfect
     * square because eavh divisor d is paired with x/d , in case of a perfect
     * sqaure there exist d0 such that d0=n/d0
     * 
     * 2 - lets count the number subarrays whose XOR has an odd number of divisors
     * 
     * 3 - now basiclay we need for each r to count number of l such that P[r]^P[l]
     * = x*x
     * we can brute force in O(n*sqrt(n))
     * 
     */

    static void testcase() {
        int n = in.nextInt();
        int A[] = in.readArray(n);
        long fr[] = new long[4 * n + 1];
        int p[] = new int[n + 1];
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] ^ A[i - 1];
        fr[0] = 1;
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int x = 0; x * x <= 2 * n; x++) {
                ans += fr[p[i] ^ (x * x)];
            }
            fr[p[i]]++;
        }

        // dbg(" ");
        ans = (long) (n * 1L * (n + 1) * 1L / 2) - ans;
        out.println(ans);

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
