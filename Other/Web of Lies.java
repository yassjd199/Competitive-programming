/*
 * Author: yassjd199
 * https://codeforces.com/contest/1549/problem/C
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

    static void testcase() {
        int n = in.nextInt(), m = in.nextInt();
        int cnt[] = new int[n];
        int curAns = 0;
        for (int i = 0; i < m; i++) {
            int a = in.nextInt(), b = in.nextInt();
            a--;
            b--;
            if (a > b)
                cnt[b]++;
            else
                cnt[a]++;
        }
        for (int i = 0; i < n; i++)
            if (cnt[i] == 0)
                curAns++;
        int q = in.nextInt();
        while (q-- > 0) {
            int typ = in.nextInt();
            if (typ == 3) {
                out.println(curAns);
                continue;
            }
            int u = in.nextInt();
            int v = in.nextInt();
            u--;
            v--;
            if (typ == 1) {
                if (u > v) {
                    if (cnt[v] == 0)
                        curAns--;
                    cnt[v]++;
                } else {
                    if (cnt[u] == 0)
                        curAns--;
                    cnt[u]++;
                }
            } else {
                if (u > v) {
                    if (cnt[v] == 1)
                        curAns++;
                    cnt[v]--;
                } else {
                    if (cnt[u] == 1)
                        curAns++;
                    cnt[u]--;
                }
            }
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
