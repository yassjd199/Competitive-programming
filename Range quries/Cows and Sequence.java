/*
 * Author: yassjd199
 * https://codeforces.com/contest/284/problem/C
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

public class G {

    static final int N = 1000006;
    static final int MOD = 1000000000 + 7;
    static int[] dx = { 0, 0, -1, 1, -1, -1, 1, 1 };
    static int[] dy = { -1, 1, 0, 0, -1, 1, -1, 1 };
    static final double EPS = 1e-9;
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static long[] st = new long[4 * N];
    static long[] lz = new long[4 * N];
    static long[] a = new long[N];
    static int n;

    static long merg(long l, long r) {
        return l + r;
    }

    static void push(int cur, int s, int e) {
        if (lz[cur] != 0) {
            st[cur] += (e - s + 1L) * lz[cur];
            if (s != e) {
                lz[2 * cur + 1] += lz[cur];
                lz[2 * cur + 2] += lz[cur];
            }
            lz[cur] = 0;
        }
    }

    static void upd_rng(int l, int r, long val, int cur, int s, int e) {
        push(cur, s, e);
        if (e < l || r < s)
            return;
        if (l <= s && e <= r) {
            lz[cur] = val;
            push(cur, s, e);
            return;
        }
        int m = (s + e) >> 1;
        upd_rng(l, r, val, 2 * cur + 1, s, m);
        upd_rng(l, r, val, 2 * cur + 2, m + 1, e);
        st[cur] = merg(st[2 * cur + 1], st[2 * cur + 2]);
    }

    static void upd_rng(int l, int r, long val) {
        upd_rng(l, r, val, 0, 0, n - 1);
    }

    static long query(int l, int r, int cur, int s, int e) {
        if (e < l || s > r)
            return 0L;
        push(cur, s, e);
        if (s >= l && e <= r)
            return st[cur];
        int m = (s + e) >> 1;
        return merg(query(l, r, 2 * cur + 1, s, m), query(l, r, 2 * cur + 2, m + 1, e));
    }

    static long query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }

    static void testcase() {
        n = in.nextInt();
        int q = n;
        n++;
        int curPos = 0;
        while (q-- > 0) {

            int typ = in.nextInt();
            if (typ == 1) {
                int len = in.nextInt();
                long x = in.nextLong();
                upd_rng(0, len - 1, x);
            } else if (typ == 2) {
                long k = in.nextLong();
                curPos++;
                upd_rng(curPos, curPos, k);

            } else {
                upd_rng(curPos, curPos, -query(curPos, curPos));
                curPos--;
            }
            out.printf("%.9f\n", (query(0, curPos) * 1.0 / (curPos + 1) * 1.0));

        }

    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        int t = 1;
        // t = in.nextInt();
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
