/*
 * Author: yassjd199
 * https://codeforces.com/contest/2104/problem/D
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
    static final int MX = 10000000;
    static int n, A[];

    static ArrayList<Integer> primes = new ArrayList<>();
    static boolean p[] = new boolean[MX];

    static void Sieve() {
        for (long i = 2; i < MX; i++) {
            if (p[(int) i])
                continue;
            primes.add((int) i);
            for (long j = i * i; j < MX; j += i) {
                p[(int) j] = true;
            }
        }
    }

    static boolean ok(int X) {
        long coins = 0;
        for (int i = n - 1, j = 1; i >= X; i--, j++) {
            if (A[i] > primes.get(n - X - j))
                coins += (A[i] * 1L - primes.get(n - X - j) * 1L);

        }

        for (int i = n - 1, j = 1; i >= X; i--, j++) {
            if (A[i] < primes.get(n - X - j))
                coins += (A[i] * 1L - primes.get(n - X - j) * 1L);
            if (coins < 0)
                return false;

        }
        return true;
    }

    static void testcase() {
        n = in.nextInt();
        A = in.readArray(n);
        Arrays.sort(A);

        int l = 0, r = n, ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;

            if (ok(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;

            }

        }
        out.println(ans);

    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        Sieve();
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
