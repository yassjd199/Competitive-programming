/*
 * Author: yassjd199
 * https://codeforces.com/contest/1549/problem/D
 * If you figured out the math, as a hint for implementation, consider sparsetables (or segment tree ) with 2 pointers 
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

    static class SparseTable {
        public int[] log;
        public long[][] table;
        public int N;
        public int K;

        public SparseTable(long[] arr) {
            this.N = arr.length + 1;
            log = new int[N + 2];
            K = Integer.numberOfTrailingZeros(Integer.highestOneBit(N));
            table = new long[N][K + 1];
            buildLog();
            for (int i = 0; i < arr.length; i++)
                table[i][0] = arr[i];
            for (int j = 1; j <= K; j++)
                for (int i = 0; i + (1 << j) <= arr.length; i++)
                    table[i][j] = merg(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }

        private void buildLog() {
            log[1] = 0;
            for (int i = 2; i <= N + 1; i++)
                log[i] = log[i / 2] + 1;
        }

        private long merg(long l, long r) {
            return gcd(l, r);
        }

        public long query(int L, int R) {
            int len = log[R - L + 1];
            return merg(table[L][len], table[R - (1 << len) + 1][len]);
        }
    }

    static int n;

    static void testcase() {
        n = in.nextInt();
        long A[] = new long[n];
        for (int i = 0; i < n; i++) {
            A[i] = in.nextLong();
        }
        if (n == 1) {
            out.println(1);
            return;
        }
        long D[] = new long[n - 1];
        for (int i = 0; i < n - 1; i++) {
            D[i] = abs(A[i + 1] - A[i]);
        }

        SparseTable sp = new SparseTable(D);

        int ans = 0;

        for (int l = 0, r = 0; r < n - 1; r++) {
            long x = sp.query(l, r);
            while (l <= r && x == 1) {
                x = sp.query(++l, r);
            }
            if (x != 1)
                ans = max(ans, r - l + 1);
        }

        out.println(ans + 1);
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

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
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
