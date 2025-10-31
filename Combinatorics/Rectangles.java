/*
 * Author: yassjd199
 * https://codeforces.com/contest/844/problem/B
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

    static void testcase() {
        int n = in.nextInt();
        int m = in.nextInt();
        int G[][] = new int[n][];
        for (int i = 0; i < n; i++) {
            G[i] = in.readArray(m);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int cnt1 = 0;
            for (int j = 0; j < m; j++) {
                cnt += G[i][j];
                cnt1 += (1 - G[i][j]);
            }
            ans += (1L << cnt);
            ans += (1L << cnt1);
            ans -= 2;
        }

        for (int j = 0; j < m; j++) {
            int cnt = 0;
            int cnt1 = 0;
            for (int i = 0; i < n; i++) {
                cnt += G[i][j];
                cnt1 += (1 - G[i][j]);
            }
            ans += (1L << cnt);
            ans += (1L << cnt1);
            ans -= 2;

        }
        ans -= (n * m);
        out.println(ans);

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
