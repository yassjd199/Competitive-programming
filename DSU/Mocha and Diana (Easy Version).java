/*
 * Author: yassjd199
 * https://codeforces.com/contest/1559/problem/D1
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

    static class DSU {
        private int[] p;
        private int[] rnk;
        private int Sz;

        public DSU(int N) {
            p = new int[N + 1];
            rnk = new int[N + 1];
            this.Sz = N;
            for (int i = 0; i <= N; i++) {
                p[i] = i;
                rnk[i] = 1;
            }
        }

        // with path compression, no find by rank
        public int find(int x) {
            return p[x] == x ? x : (p[x] = find(p[x]));
        }

        // public void merge(int x, int y) {
        // x = find(x);
        // y = find(y);
        // if (x == y)
        // return;
        // p[x] = y;
        // Sz--;
        // }
        public boolean same(int x, int y) {
            x = find(x);
            y = find(y);
            return (x == y);
        }

        public void merg(int x, int y) {
            x = find(x);
            y = find(y);
            if (rnk[y] > rnk[x]) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            rnk[x] += rnk[y];
            rnk[y] = 0;
            p[y] = x;
            Sz--;
        }

        public int size() {
            return Sz;
        }
    }

    static void testcase() {
        int n = in.nextInt(), m1 = in.nextInt(), m2 = in.nextInt();

        DSU d1 = new DSU(n);
        DSU d2 = new DSU(n);

        for (int i = 0; i < m1; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            a--;
            b--;
            d1.merg(a, b);
        }
        for (int i = 0; i < m2; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            a--;
            b--;
            d2.merg(a, b);
        }
        ArrayList<int[]> ans = new ArrayList<>();
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u == v)
                    continue;
                if (!d1.same(u, v) && !d2.same(u, v)) {
                    d1.merg(u, v);
                    d2.merg(u, v);
                    ans.add(new int[] { u + 1, v + 1 });
                }
            }
        }
        out.println(ans.size());
        for (int[] x : ans) {
            out.println(x[0] + " " + x[1]);
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
